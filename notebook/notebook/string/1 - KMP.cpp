1. KMP.cpp

string t;
string p;
int lps[p.size()]; // set it with 0's

void init() {
	int j = 0;
	for (int i = 0; i < p.size(); i++) {
		while (j && p[i] != p[j]) j = lps[j - 1];
		if (p[i] == p[j]) j++;
		lps[i] = j;
	}
}

void kmp() {
	int n = t.size();
	int m = p.size();
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j & p[j] != s[i]) j = lps[j - 1];
		if (p[j] == s[i]) j++;
		if (j == m) {
			//process
			j = pf[j - 1];
		}
	}
}
