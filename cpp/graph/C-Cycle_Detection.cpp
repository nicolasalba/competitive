const int N = 1e5 + 10;
vpl adj[N];
int vis[N];
vpl res;
vpl edge;

void dfs(int x) {
    if (vis[x] == 2) return;
    vis[x] = 1;
    each(z, adj[x]) {
        int y, i;
        tie(y, i) = z;
        if (vis[y] == 1) {
            pl a = {-1, -1};
            if (edge[i] == a) {
                edge[i] = {y, x};
            }
        } else {
            pl a = {-1, -1};
            if (edge[i] == a) {
                edge[i] = {x, y};
            }
        }
        if (vis[y] == 0) dfs(y);
    }
    vis[x] = 2;
}
 
 
 
void test_case() {
    int n, m;
    cin >> n >> m;
    edge = vpl(m);
    rep(i, 0, m) {
        int x, y;
        cin >> x >> y;
        adj[x].pb({y, i});
        adj[y].pb({x, i});
        edge[i] = {-1, -1};
    }
    rep(i, 1, n + 1) {
        dfs(i);
    }
    each(r, edge) {
        cout << r.F << " " << r.S << "\n";
    }
}
