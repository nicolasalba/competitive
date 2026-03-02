/* Multiple Knacksack Time complexity is O(W*N*sum)
W = capacity,  sum is: for (x in copies) sum += log2(x) 
n<=100, capacity<=10^5, copies[i]<=1000 */
ll multipleKnacksack(vl &value, vl& weight, 
                              vl&copies, ll capacity) {
  vl vs,ws; ll n = value.size();
  for (int i = 0;i<n;i++) {
    ll h=value[i],s=weight[i],k=copies[i];
    ll p = 1;
    while (k>p) { k-=p; vs.pb(s*p); ws.pb(h*p); p*=2; }
    if (k) { vs.pb(s*k); ws.pb(h*k); }
  }
  vl dp(capacity+1);
  for (int i =0;i<ws.size();i++) // 0-1 knacksack
      for (int j = capacity;j>=ws[i];j--) 
        dp[j] = max(dp[j],dp[j-ws[i]] + vs[i]); 
  return dp[capacity]; 
}
