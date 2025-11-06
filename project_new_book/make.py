#!/usr/bin/env python3

from argparse import ArgumentParser
from dataclasses import dataclass
import os
from pathlib import Path
import platform
import subprocess
import sys
import time
import re
from typing import Any

EXT_WHITELIST = [".cpp", ".c", ".typ", ".txt", ".py"]
PLATFORM_TYPST = {
    "Windows": "typst-windows.exe",
    "Linux": "typst-linux",
}

NEWLINE = "\n"

base_path = Path(__file__).parent

conf: "Conf"

def section_name(raw: str) -> str | None:
    if raw.startswith("."):
        return None
    return " ".join(w.capitalize() for w in raw.split())

def file_name(name: str) -> str | None:
    for ext in EXT_WHITELIST:
        if name.endswith(ext):
            if(ext.endswith(".tex")):
                print(name)
            name = name.removesuffix(ext)
            name = re.split("[-_\s]+", name)
            return " ".join(w.lower() for w in name)
    return None

def file_contents(filename: str, raw: str) -> str:
    if filename.endswith(".typ"):
        # Treat as typst source
        return Verbatim("[\n" + raw.strip() + "\n]")

    # Treat as code
    extension = ""
    if "." in filename:
        extension = filename.split(".")[-1]
    return Verbatim("```"+extension+"\n"+raw.strip()+"\n```")
    return Verbatim("["+"\n".join("#box(```"+extension+"\n"+line+"\n```)" for line in raw.strip().split("}\n"))+"]")

class Verbatim(str):
    pass

def serialize(val: Any) -> str:
    if isinstance(val, Verbatim):
        return val
    if isinstance(val, bool):
        return "true" if val else "false"
    if isinstance(val, float) or isinstance(val, int):
        return str(val)
    if isinstance(val, str):
        return '"' + val.replace("\\", "\\\\").replace("\"", "\\\"") + '"'
    if isinstance(val, list) or isinstance(val, tuple):
        return "(" + "".join(serialize(subval) + "," for subval in val) + ")"
    if not isinstance(val, dict):
        val = {attrname: getattr(val, attrname) for attrname in dir(val) if not attrname.startswith("_")}
    if not val:
        return "(:)"
    for k in val:
        if not isinstance(k, str):
            raise RuntimeError("dictionary key must be a string")
    return "("+",".join(serialize(k) + ":" + serialize(v) for k, v in val.items())+")"

def compose(sections: list[tuple[str, list[tuple[str, str]]]]) -> str:
    args = {
        "conf": conf,
        "content": sections,
    }
    return f"""
#import "template.typ": compose
#compose({serialize(args)})
    """

def limpiar_saltos(texto: str) -> str:
    # 1. Si la línea está vacía o solo tiene espacios/tabs, conviértela en un salto limpio
    texto = re.sub(r'^[ \t]+$', '', texto, flags=re.MULTILINE)
    
    # 2. Reducir múltiples saltos de línea consecutivos a uno solo
    texto = re.sub(r'\n+', '\n', texto)
    
    return texto.strip()

def unir_lineas_cortas(texto: str, max_len: int = 55) -> str:
    lineas = texto.split('\n')
    resultado = []

    for linea in lineas:
        linea = linea.rstrip()
        not_line_comment = not linea.startswith("//")
        if not_line_comment and resultado and len(resultado[-1] + " " + linea.strip()) <= max_len:
            # unir con la línea anterior si esta es corta
            resultado[-1] += ' ' + linea.strip()
        else:
            resultado.append(linea)

    return '\n'.join(resultado)


def ingest() -> list[tuple[str, list[tuple[str, str]]]]:
    sections = []
    for dirname in sorted(os.listdir(base_path)):
        dir = base_path.joinpath(dirname)
        if dir.is_dir():
            secname = section_name(dirname)
            if secname is not None:
                sec = []
                for filename in os.listdir(dir):
                    fname = file_name(filename)
                    if fname is not None:
                        filepath = dir.joinpath(filename)
                        txt = filepath.read_text()
                        txt = limpiar_saltos(txt)
                        # if not filename.endswith(".py"):
                        #     txt = unir_lineas_cortas(txt) # Comentar si no es necesario
                        sec.append((fname, file_contents(filename, txt)))
                sections.append((secname, sec))
    return sections

def compile(src: str):
    if conf.print_source:
        print("printing source code instead of compiling because --print-source flag was received", file=sys.stderr)
        print("typst source code:", file=sys.stderr)
        print(src)
    else:
        system = platform.system()
        exe_name = PLATFORM_TYPST.get(system)
        if exe_name is None:
            raise RuntimeError(f"typst binary not available for platform '{system}'")
        typst_dir = base_path.joinpath(".typst")
        exe_path = typst_dir.joinpath(exe_name)
        out_path = base_path.joinpath(conf.out)
        subprocess.run([exe_path, "compile", "--root", typst_dir, "--format", "pdf", "-", out_path], input=src.encode("utf-8"))
        print(f"wrote pdf to {conf.out}", file=sys.stderr)


@dataclass
class Conf:
    out: str
    university: str
    team: str

    print_source: bool

    font_size: Verbatim
    column_count: int
    column_gutter: Verbatim
    margin: Verbatim
    paper: str
    portrait: bool
    theme: str

    @staticmethod
    def parse() -> "Conf":
        p = ArgumentParser(description="Make a competitive programming notebook from source files")
        p.add_argument("-o", "--out", required=True, help="Output file path")
        p.add_argument("--print-source", action="store_true", help="Print Typst source instead of compiling a PDF")
        p.add_argument("-u", "--university", default="<university>", help="University name")
        p.add_argument("-t", "--team", default="<team>", help="Team name")
        p.add_argument("--font-size", default="15.984pt", help="Size of the font used for code")
        p.add_argument("--column-count", default="3", help="Number of columns")
        p.add_argument("--column-gutter", default="5mm", help="Space between columns")
        p.add_argument("--margin", default="10mm", help="Page margin")
        p.add_argument("--paper", default="a4", help="Page paper size")
        p.add_argument("--theme", default="", help="Code highlighting theme")
        p.add_argument("--portrait", action="store_true", help="Whether to orient in portrait mode")
        args = sys.argv[1:]
        confpath = base_path.joinpath("makeconf")
        if confpath.is_file():
            extra = confpath.read_text().splitlines()
            args = extra + args
        parsed = p.parse_args(args)
        attrs = {}
        for name, ty in Conf.__annotations__.items():
            attrs[name] = ty(getattr(parsed, name))
        for attrname in dir(parsed):
            if not attrname.startswith("_") and attrname not in Conf.__annotations__:
                raise NameError(f"unknown commandline attribute '{attrname}'")
        return Conf(**attrs)

def main():
    global conf
    start = time.monotonic()

    conf = Conf.parse()

    print("processing input files", file=sys.stderr)
    sections = ingest()
    src = compose(sections)

    print("compiling to pdf", file=sys.stderr)
    compile(src)
    
    print(f"done in {time.monotonic() - start:.2f}s", file=sys.stderr)

if __name__ == "__main__":
    main()