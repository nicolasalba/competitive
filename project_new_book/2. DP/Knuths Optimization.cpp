/*  Knuth opt for interval DP:
dp[i][j]=min_{i<=k<j} dp[i][k]+dp[k+1][j]+c[i][j]
If opt monotone:
opt[i][j-1] <= opt[i][j] <= opt[i+1][j]
Needs quadrangle/Monge + w(i,j) monotone.
Time: O(n^2) */
void test_case() {
  cin >> n;nums.assign(n,0);pf.assign(n+1,0);
  for (int i =0;i<n;i++) cin>>nums[i], pf[i+1] = pf[i] + nums[i];
  for (int i = 0;i<n;i++){// base case, depends of dp
    dp[i][i] = 0; opt[i][i] = i; }
  for(int i=n-2;i>=0;i--) {
      for (int j = i+1;j<n;j++) {
        dp[i][j] = inf; //set to inf,-1,or flag
        ll cost = sum(i,j); // depends of problem
        for (int k = opt[i][j-1]; k<= min(j-1ll,opt[i+1][j]);k++) {
          ll actual = dp[i][k] + dp[k+1][j] + cost;
          if (actual < dp[i][j]) { 
            dp[i][j] = actual; opt[i][j] = k;
          } } } }
  cout << dp[0][n-1] << "\n";
}
