// N <= 5000, M <= 30000, C <= 1e9, 300ms
 
const int INF = INT32_MAX;

struct flowEdge{
    ll to, rev, f, cap;
};


struct max_flow {

    vector<vector<flowEdge>> G;

    max_flow(int n) : G(n) {
        nodes = n;
    }

    // Añade arista (st -> en) con su capacidad
    void addEdge(int st, int en, int cap) {
        flowEdge A = {en, (int)G[en].size(), 0, cap};
        flowEdge B = {st, (int)G[st].size(), 0, 0};
        G[st].pb(A);
        G[en].pb(B);
    }

    ll nodes, S, T; // asignar estos valores al armar el grafo G
                 // nodes = nodos en red de flujo. Hacer G.clear(); G.resize(nodes);
    vl work, lvl;
   

    bool bfs() {
        int qt = 0;
        queue<ll> q;
        q.push(S);
        lvl.assign(nodes, -1);
        lvl[S] = 0;
        while (q.size()) {
            int v = q.front(); q.pop();
            for (flowEdge &e : G[v]) {
                int u = e.to;
                if (e.cap <= e.f || lvl[u] != -1) continue;
                lvl[u] = lvl[v] + 1;
                q.push(u);
            }
        }
        return lvl[T] != -1;
    }

    ll dfs(ll v, ll f) {
        if (v == T || f == 0) return f;
        for (ll &i = work[v]; i < G[v].size(); i++) {
            flowEdge &e = G[v][i];
            ll u = e.to;
            if (e.cap <= e.f || lvl[u] != lvl[v] + 1) continue;
            ll df = dfs(u, min(f, e.cap - e.f));
            if (df) {
                e.f += df;
                G[u][e.rev].f -= df;
                return df;
            }
        }
        return 0;
    }

    ll maxFlow(ll s, ll t) {
        S = s;
        T = t;
        ll flow = 0;
        while (bfs()) {
            work.assign(nodes, 0);
            while (true) {
                ll df = dfs(S, INF);
                if (df == 0) break;
                flow += df;
            }
        }
        return flow;
    }
};
