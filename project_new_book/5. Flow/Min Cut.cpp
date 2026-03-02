/* Min-cut after max-flow:
1) Run maxFlow. 2) DFS/BFS from source in residual
   → reachable set S
3) Edges (u∈S, v∉S) in original are min-cut edges */

void test_case() {
  ll n,m;cin>>n>>m; vvl g(n);
  Dinitz f(n,0,n-1);
  for (int i =0;i<m;i++) {
    ll x, y;cin >>x >> y;x--,y--;
    g[x].pb(y); g[y].pb(x);//check bidirect or not
    f.addEdge(x,y,1); f.addEdge(y,x,1);
  } f.maxFlow(); // step 1
  vvl residual(n); // Step 2
  for (int i =0;i<n;i++) for (auto j:f.G[i]) 
    if ((j.f<0 && j.cap==0) || (j.f==0 && j.cap > 0))
      residual[i].pb(j.to); // residual graph
  set<ll> vis;
  function<void(int)> dfs = [&](int x) {
    vis.insert(x); // dfs on residual from source
    for (auto y:residual[x])if(!vis.count(y)) dfs(y);};
  dfs(0);
  vector<pair<ll,ll>> ans; // step 3
  for (auto x : vis) for (auto y : g[x]) 
    if (!vis.count(y))  ans.pb({x,y});
  cout << ans.size() << "\n";
  for (auto e : ans) cout<<e.F+1<<" "<<e.S+1<<"\n";
}
