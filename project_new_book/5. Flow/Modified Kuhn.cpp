void test_case() {
  ll n1, n2, m; cin >> n1 >> n2 >> m;
  vector<vector<ll>> adjL(n1+1), adjR(n2+1);
  vector<ll> visL(n1+1), visR(n2+1);
  vector<ll> matchL(n1+1), matchR(n2+1);
  ll time = 0;
  for (int i =0;i<m;i++) { ll x, y; cin >> x >> y;
    adjL[x].pb(y); adjR[y].pb(x); }
  vector<ll> pref(n2+1);
  auto kuhn = [&](auto && self, ll x) -> bool {
    if (visR[x]==time) return false; visR[x] = time;
    for (auto y : adjR[x]) {
      if (!matchL[y] || self(self,matchL[y])) {
        matchL[y] = x; matchR[x] = y;
        return true; } }
    return false; };

  for (int r = 1; r <= n2; r++) {
    time++; pref[r] = pref[r-1] + kuhn(kuhn,r); }

  pair<ll,ll> efe  = {1e18, false};
  auto mnkuhn=[&](auto &&self,ll x,ll r)->pair<ll,ll>{
    if (visL[x] == time) return efe; visL[x] = time;
    auto ans = efe;
    for (auto y : adjL[x]) {
      if (y <= r) continue;
      if (!matchR[y]) { ans = min(ans, {y, true}); } 
      else { auto nxt = self(self, matchR[y],r);
        if (nxt.S) ans = min(ans, nxt); } }
    return ans; };
  auto matchmin=[&](auto &&self,ll x,ll target,ll r) {
      if (visL[x] == time) return false;// -> bool
      visL[x] = time;
      for (auto y : adjL[x]) {
        if (y <= r) continue;
        if (y == target || (matchR[y] 
                  && self(self,matchR[y],target,r))) {
          matchR[y] = x; matchL[x] = y; return true; }}
      return false;};
  vl diff(n2+1); vector<vl> newmatch(n2+1);
  for (int r = 1; r <= n2; r++) {
    if (matchR[r]) {
      time++;
      auto ans = mnkuhn(mnkuhn,matchR[r], r);
      diff[r]--;
      if (ans.S) {
        newmatch[ans.F].pb(r); time++;
        matchmin(matchmin, matchR[r], ans.F, r);}}}
  for (int r = 1; r <= n2; r++) {
      for (auto & x : newmatch[r]) diff[x]++;
      ll f = pref[r]; // f=max match of subarray
      addflow(1,r,f);
      for (int l = 1; l < r; l++) {
        f += diff[l]; addflow(l+1,r,f); } } }
