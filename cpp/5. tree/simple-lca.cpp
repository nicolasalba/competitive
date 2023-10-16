// view: https://cses.fi/problemset/task/1688/
vector<vector<ll>> children;
vector<vector<ll>> up;
const int LOG = 18; // 2e5
vector<ll> depth;

void dfs(ll x, ll d =0) {
    depth[x] = d;
    for (auto y : children[x]) {
        dfs(y, d + 1);
    }
}

ll kParent(ll x, ll k) {
    ll i = 0;
    while (k) {
        if (k & 1) {
            x = up[i][x];
        }
        k >>= 1;
        i++;
    }
    return x;
}

ll query(ll x, ll y) {
    if (depth[x] < depth[y]) {
        swap(x, y);
    }

    x = kParent(x, depth[x] - depth[y]);
    if (x == y) {
        return x;
    }
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[i][x] != up[i][y]) {
            x = up[i][x];
            y = up[i][y];
        }
    }
    return up[0][x];
}

void test_case() {
    ll n, q;
    cin >> n >> q;
    children = vector<vector<ll>>(n);
    up = vector<vector<ll>>(LOG, vector<ll>(n, 0));
    depth = vector<ll>(n);
    for (int i = 1; i < n; i++) {
        ll p;
        cin >> p;
        p--;
        children[p].pb(i);
        up[0][i] = p;
    }
    dfs(0);
    for (int i = 1; i < LOG; i++) {
        for (int j = 0; j < n; j++) {
            up[i][j] = up[i-1][up[i-1][j]];
        }
    }
    for (int i = 0; i < q; i++) {
        ll x, y;
        cin >> x >> y;
        x--,y--;
        cout << query(x, y) + 1<< "\n";
    }
}
