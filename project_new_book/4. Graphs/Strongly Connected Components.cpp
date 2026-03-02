/* Tarjan SCC (0-indexed)
comp[v] = id of component of v
SCC = number of components
adjComp() → DAG of components */
struct Tarjan {
  vl low, pre, comp;  ll cnt, SCC, n;  vvl g;
  const int inf = 1e9;
  Tarjan(vvl &adj) {
    n = adj.size();  g = adj; low = vl(n);
    pre = vl(n,-1); cnt = SCC = 0; comp = vl(n,-1);
    for (int i = 0;i<n;i++) if (pre[i]== -1) tarjan(i);
  }
  stack<int> st;
  void tarjan(int u) {
    low[u] = pre[u] = cnt++;  st.push(u);
    for (auto &v : g[u]) {
      if (pre[v] == -1) tarjan(v);//use this for all u
      low[u] = min(low[u],low[v]);
    }
    if (low[u] == pre[u]) {
      while (true) {
        int v = st.top();st.pop(); low[v] = inf;
        comp[v] = SCC; if (u == v) break;
      }
      SCC++;
    }
  }

  vvl adjComp() {
    vvl adj(SCC);
    for (int i = 0;i<n;i++) {
      for (auto j : g[i]) {
        if (comp[i] == comp[j]) continue;
        adj[comp[i]].pb(comp[j]);
      }
    }
    for (int i = 0;i<SCC;i++) {
      sort(all(adj[i]));
      adj[i].erase(unique(all(adj[i])),adj[i].end());
    }
    return adj;
  }
};
/* Another way is with with Kosaraju:
  1. Find topological order of G
  2. Run dfs in topological order in reverse Graph
    to find o connected component*/