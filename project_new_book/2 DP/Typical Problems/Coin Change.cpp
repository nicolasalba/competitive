// infinite number of coins
// Get the minimum number of coins that sum a value.
void test_case() {
    ll n, x;
    cin >> n >> x;
    vl dp(x + 1, inf - 1);
    vl coin(n);
    rep(i, 0, n) cin >> coin[i];
    dp[0] = 0;
    rep(i, 0, x) {
        each(c, coin) {
            if (c + i > x) continue;
            dp[i + c] = min(dp[i + c], dp[i] + 1);
        }
    }
    if (dp[x] + 1== inf) {
        cout << "-1\n";
    } else {
        cout << dp[x] << "\n";
    }
}
