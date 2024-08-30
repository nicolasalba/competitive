/*
Knuth's Optimization

For dp[i][j] = min_{i<=k<j} dp[i][k] + dp[k+1][j] + cost[i][j]

Optimizing that from O(n^3) to O(n^2), it's required to hold the following:
opt[i][j] = optimal splitting point of dp[i][j], the 'k' the minimizes the above definition

opt[i][j-1] <= opt[i][j] <= opt[i+1][j]

You can demostrate that by the following:

a<=b<=c<=d
cost(b,c) <= cost(a,d), // an contained interval is <= of the interval
cost(a,c)+cost(b,d) <= cost(a,d)+cost(b,c) // partial intersection <= total intersection

Complexity: O(n^2)
*/
void test_case() {
    cin >> n;nums.assign(n,0);pf.assign(n+1,0); // READ input!!!
    for (int i =0;i<n;i++) cin>>nums[i], pf[i+1] = pf[i] + nums[i];
    
    for (int i = 0;i<n;i++) { // base case
        dp[i][i] = 0; // depends of the dp!!!!
        opt[i][i] = i;
    }

    for (int i =n-2;i>=0;i--) {
        for (int j = i+1;j<n;j++) {
            dp[i][j] = inf; // set to inf, any option is better, or use -1 or a flag!!
            ll cost = sum(i,j); // depends of problem
            for (int k = opt[i][j-1]; k<= min(j-1ll,opt[i+1][j]);k++) {
                ll actual = dp[i][k] + dp[k+1][j] + cost;
                if (actual < dp[i][j]) { // if flag '-1' used, change here!!
                    dp[i][j] = actual;
                    opt[i][j] = k;
                }
            }
        }
    }
    
    cout << dp[0][n-1] << "\n";
}
