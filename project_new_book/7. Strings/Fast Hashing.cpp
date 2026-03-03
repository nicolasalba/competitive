#define ll long long
const int N = 1e6 + 9; // Max size
#define F first
#define S second

int power(ll n, ll k, const int mod) {
  int ans = 1 % mod; n %= mod; if (n < 0) n += mod;
  while (k) { if (k & 1) ans = (ll) ans * n % mod;
    n = (ll) n * n % mod; k >>= 1; }
  return ans; }
const int MOD1 = 127657753, MOD2 = 987654319;
const int p1 = 137, p2 = 277;
int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void init() { // Call init() first!!!
  pw[0] =  {1, 1};
  for (int i = 1; i < N; i++) {
    pw[i].F = 1LL * pw[i - 1].F * p1 % MOD1;
    pw[i].S = 1LL * pw[i - 1].S * p2 % MOD2;
  }
  ip1 = power(p1, MOD1 - 2, MOD1);
  ip2 = power(p2, MOD2 - 2, MOD2);
  ipw[0] =  {1, 1};
  for (int i = 1; i < N; i++) {
    ipw[i].F =1LL * ipw[i - 1].F * ip1 % MOD1;
    ipw[i].S =1LL* ipw[i - 1].S * ip2 % MOD2;
  }
}
struct Hashing {
  int n; string s; // 0 - indexed
  vector<pair<int, int>> hs; // 1 - indexed
  Hashing() {}
  Hashing(string _s) {
    n = _s.size(); s = _s;
    hs.emplace_back(0, 0);
    for (int i = 0; i < n; i++) {
      pair<int, int> p;
      p.F =(hs[i].F+1LL*pw[i].F*s[i]%MOD1) % MOD1;
      p.S =(hs[i].S+1LL*pw[i].S*s[i]%MOD2) % MOD2;
      hs.push_back(p);
    }
  }
  pair<int, int> get_hash(int l, int r) { // 1-indexed
    assert(1 <= l && l <= r && r <= n);
    pair<int, int> ans;
    ans.F=(hs[r].F-hs[l-1].F+MOD1)*1LL*ipw[l-1].F%MOD1;
    ans.S=(hs[r].S-hs[l-1].S+MOD2)*1LL*ipw[l-1].S%MOD2;
    return ans;
  }
  pair<int,int> get(int l, int r) { // 0-indexed
    return get_hash(l+1,r+1); }
  pair<int, int> get_hash() {
    return get_hash(1, n); }
};
