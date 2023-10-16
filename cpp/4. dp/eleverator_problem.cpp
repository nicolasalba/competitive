// Given n <= 20 persons, print the minimum number of travels
// to move everyone in a elevator with capacity k.

ll n, k;
vl nums;
vector<pair<ll,ll>> dp;
 
// minimum travels, last travel with minimum weight. 
// use  f((1 << n) - 1).F 
pair<ll,ll> f(ll mask) {
    if (dp[mask] != make_pair(-1ll, -1ll)) {
        return dp[mask];
    }
    if (mask == 0) {
        return dp[mask] = {0, k};
    }
    dp[mask] = {n + 1, 0}; // one person in a travel, or use popcount.
    for (int i = 0; i < n; i++) {
        // person i is the last to enter to elevator.
        if ((mask >> i) & 1) {
            auto actual = f(mask ^ (1 << i)); // best option without this last person.
            if (actual.S + nums[i] <= k) {
                actual.S += nums[i];
                // what happened if there are a better minimum.
                // well in that case the last person should be other one.
                // so we are trying all options that last person will be better.
            } else {
                actual.S = nums[i];
                actual.F++;
            }
            dp[mask] = min(dp[mask], actual);
        }
    }
    return dp[mask];
}


// Iterative
void test_case() {
    ll n, k;
    cin >> n >> k;
    vl nums(n);
    vector<pair<ll,ll>> dp(1 << n, {n+1, 0});
    for (int i =0; i < n; i++) cin >> nums[i];
    dp[0] = {0, k};
    for (int i = 1; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i& (1 << j)) {
                auto actual = dp[i ^ (1 << j)];
                if (actual.S + nums[j] <= k) {
                    actual.S += nums[j];
                } else {
                    actual.F++;
                    actual.S = nums[j];
                }
                dp[i] = min(dp[i], actual);
            }
        }
    }
    cout << dp[(1 << n) -1].F << "\n";
}
