/*
You are given a string S consisting of digits and positive integers L and R for each of T test cases. Solve the following problem.

For a positive integer x, let us define f(x) as the number of contiguous substrings of the decimal representation of 
x (without leading zeros) that equal S.
Find L <= K <= R
∑f(k).
*/

// Copy kmp automaton
ll dp[20][20][20][2][2];

ll ff(ll pos, ll posAut, ll matches, bool free, bool anyNumber) {
    if (!anyNumber) {
        matches = 0;
        posAut = 0;
    }
    ll match = anyNumber ? p.size() == posAut : 0;
    if (pos == t.size()) {
        if (anyNumber) {
            return matches + match;
        } else {
            return 0;
        }
    }
    if (dp[pos][posAut][matches][free][anyNumber] != -1) {
        return dp[pos][posAut][matches][free][anyNumber];
    }
    ll ans = 0;
    for (char c = '0'; c <= '9'; c++) {
        if (!free && c > t[pos]) break;
        ans += ff(pos + 1, aut[posAut][c - L], matches + match, free || c < t[pos], anyNumber || c != '0');
    }
    return dp[pos][posAut][matches][free][anyNumber] = ans;
}

ll f(string s) {
    t = s;
    memset(dp, -1, sizeof dp);
    return ff(0, 0, 0, 0, 0);
}
