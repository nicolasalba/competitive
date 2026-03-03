//Useful to calculate reverse sos DP. 
//DP[x]=op(DP[y_1],DP[y_2],..),where x is submsk of y_i 
vector<ll> nums(n);
for (int i =0;i<n;i++) {
  nums[i] = rd(); // read submask, and set init state
  dp[nums[i]] = min(dp[nums[i]], {0, i}); }
// You can switch fors depends of the problem
for (int mask = (1<<m)-1; mask >= 0; mask--) { 
  if (dp[mask].first > 0) continue; // Don't propagate
  for (int i =0;i<m;i++) {
    if ((mask>>i)&1) { // Propagate to all submasks
      auto nxt = dp[mask]; nxt.first--; 
      dp[mask^(1ll<<i)]=min(dp[mask^(1ll<<i)],nxt);}}}
