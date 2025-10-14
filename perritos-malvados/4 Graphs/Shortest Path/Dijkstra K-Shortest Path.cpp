// Using djisktra, finds the k shortesth paths from 1 to n
// 2≤n≤10^5, 1≤m≤2⋅10^5, 1≤weight≤10^9, 1≤k≤10
// complexity seems O(k*m)
#define P pair<ll,ll>
void test_case() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> visited(n+1, 0);
    vector<vector<pair<ll,ll>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
    }
    vector<ll> ans;
    priority_queue<P,vector<P>, greater<P>> q;
    q.push({0, 1});
    ll kk = k;
    while (q.size()) {
        ll x = q.top().S;
        ll z = q.top().F;
        q.pop();
        if (visited[x] >= kk) {
            continue;
        }
        visited[x]++;
        if (x == n) {
            ans.pb(z);
            k--;
            if (k == 0) break;
        }
        for (auto yy : adj[x]) {
            q.push({yy.S + z, yy.F});
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n" [i == ans.size() - 1];
    }
}
