g++ -std=c++11 -O2 -Wall test.cpp -o test

-Wall -Wextra -O2


-pedantic  warns about non-standard C++ language extensions.
-Wshadow — warns if a declared name shadows the same name in some outer level. For example, this will cause a warning:
int n;
void solve()
{
    // Solve the problem
}
int main()
{
    int n; cin >> n;
    solve();
}
-Wformat=2 — warns if an argument type in printf()/scanf() does not correspond to the format string. This is partially enabled by -Wall, but -Wformat=2 is more strict.

-Wfloat-equal — warns if two floating point values are compared directly: a == b. Usually the correct way is: fabs(a - b) < eps.

-Wconversion — warns if data can be lost in an implicit conversion.¹ Most often it is accidental assignment of a long long value to an int variable. I have this warning enabled since I failed a problem by writing pair<int, int> instead of pair<int, long long> :)

¹ An explicit cast (for example, (double)my_long_long_var) will not trigger this warning.

-Wlogical-op — warns about logical operators in places where GCC expects bitwise operators.

-Wshift-overflow=2 — warns about left shift overflows (GCC 6+).

-Wduplicated-cond — warns about repeated conditions in if (…) else if (…) (GCC 6+).

There are also -Wcast-qual и -Wcast-align, but they are less useful (though don't hurt). You can read more about GCC warnings here: https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
