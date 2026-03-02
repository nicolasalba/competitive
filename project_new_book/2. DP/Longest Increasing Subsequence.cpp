int lis(vl &nums) {
  vl best;  int n = nums.size();
  for (int i = 0; i < n; i++) {
    // For non-decreasing
    // int idx=upper_bound(all(best),nums[i])- bst.be() 
    // For increasing
    int idx = 
        lower_bound(all(best),nums[i])-best.begin();
    if (idx == best.size()) best.pb(nums[i]);
    else best[idx] = min(best[idx], nums[i]);
  } return best.size(); }
