// editDistance(a, b, a.size(), b.size());

// Cuantas operaciones, (insert, remove, remplazar) necesito
// para que string a y b sean iguales.
int editDistance(string a, string b, int m, int n)
{
    if (m == 0) return n;
    if (n == 0) return m;
    if (a[m - 1] == b[n - 1])
        return editDistance(a, b, m - 1, n - 1);

    return 1 + min({editDistance(a, b, m, n - 1), // Insert
                    editDistance(a, b, m - 1, n), // Remove
                    editDistance(a, b, m - 1, n - 1) // Replace
                });
}

// My own
ll editDistance(string &s, string &t) {
    ll n = s.size();
    ll m = t.size();
    vvl dp(n+1, vl(m+1, 0));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (min(i, j) == 0) dp[i][j] = max(i, j);
            else if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
        }
    }
    return dp[n][m];
}
