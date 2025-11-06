vector<vector<ll>> adj(2e5+5);
vector<ll> visited(2e5);
bool ok = false; // if cycle was found ok is true
vector<ll> cycle; // the found cycle
void dfs(ll x, vector<ll> &st) {
    if (ok || visited[x] == 2) {
        return;
    } else if (visited[x] == 1) {
        cycle.pb(x);
        while (st.back() != x) {
            cycle.pb(st.back());
            st.pop_back();
        }
        cycle.pb(x);
        reverse(all(cycle));
        ok = true;
        return;
    }
    visited[x] = 1;
    st.pb(x);
    for (auto y : adj[x]) {
        dfs(y, st);
    }
    st.pop_back();
    visited[x] = 2;
}

void test_case() {
    ll n, m;
    cin >> n >> m;
    
    for (int i =0; i < m;i ++) {
        ll x, y;
        cin >> x >> y;
        adj[x].pb(y);
    }

    vector<ll> st;
    for (int i = 1; i <= n; i++) {
        dfs(i, st);
    }

    if (ok) {
        cout << cycle.size() << "\n";
        for (int i = 0; i < cycle.size(); i++) {
            cout << cycle[i] << " \n" [i == cycle.size() - 1];
        }
    } else {
        cout << "IMPOSSIBLE\n";
    }
}
