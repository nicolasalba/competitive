/* 
 Tarjan t(graph); provides you the SCC of that graph
 passing the adjancency list of the graph (as vector<vl>)

 This is 0-indexed, (but you can have node 0 as dummy-node)
 Use t.comp[x] to get the component of node x
 SCC is the total number of components
 adjComp() gives you the adjacency list of strongly components
*/
struct Tarjan {
    vl low, pre, comp;
    ll cnt, SCC, n;
    vvl g;
    const int inf = 1e9;

    Tarjan(vvl &adj) {
        n = adj.size();
        g = adj;
        low = vl(n);
        pre = vl(n,-1);
        cnt = SCC = 0;
        comp = vl(n,-1);

        for (int i = 0;i<n;i++)
            if (pre[i] == -1) tarjan(i);
    }

    stack<int> st;
    void tarjan(int u) {
        low[u] = pre[u] = cnt++;
        st.push(u);
        for (auto &v : g[u]) {
            if (pre[v] == -1) tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        if (low[u] == pre[u]) {
            while (true) {
                int v = st.top();st.pop();
                low[v] = inf;
                comp[v] = SCC;
                if (u == v) break;
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
            adj[i].erase(
                unique(all(adj[i])),
                adj[i].end());
        }
        return adj;
    }
};

/* Another way is with with Kosaraju:
    1. Find topological order of G
    2. Run dfs in topological order in reverse Graph
       to find o connected component
*/