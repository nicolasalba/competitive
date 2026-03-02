/*K segments, min sum (seg_sum)^2
dp[i][j] = min_k<=j dp[i-1][k-1] + cost(k,j)
D&C ok if: cost(a,c)+cost(b,d)<=cost(a,d)+cost(b,c)
Dividir un arreglo en k segmentos contiguos minimizando
(suma del segmento)^2
*/
const int mxn = 3005;
int nums[mxn], pf[mxn]; vector<ll> dp_cur, dp_before;
ll cost(ll i, ll j) {
return (pf[j+1]-pf[i])*(pf[j+1]-pf[i]); 
}
void solve(ll l, ll r, ll optl, ll optr) {
  if (r < l) return; ll mid = (l+r)>>1;
  pair<ll,int> best = {INT64_MAX, -1};
  for (int i = optl; i <= min(optr,mid); i++) {
    // check if dp_before[-1] should be 0
    ll nxt = (i ? dp_before[i-1] : 0) + cost(i,mid);
    best = min(best,{nxt,i});
  }
  dp_cur[mid] = best.first;
  ll p = best.second;
  solve(l,mid-1,optl,p);  solve(mid+1,r,p,optr);
}
void test_case() {
  ll n,k;cin>>n>>k; dp_before.assign(n,0);
  dp_cur.assign(n,0); for(int i=0;i<n;i++)
                    cin>>nums[i],pf[i+1]=pf[i]+nums[i];
  for (int i = 0;i<n;i++) dp_before[i] = cost(0,i);
  for (int i = 2; i <= k; i++) {
    solve(0,n-1,0,n-1); dp_before = dp_cur; } 
  cout << dp_before[n-1] << "\n"; } 
