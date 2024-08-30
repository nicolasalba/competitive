/* K-th Parent.cpp
Given and Tree, and Q queries to see the K-Parent of a node
*/
const int LOG = 20;
vvl parent(LOG, vl(2e5 + 10, -1));

void test_case() { // 1-based indexed
    ll n, q; cin >> n >> q; 
 
    for (int i = 0; i < n - 1; i++)
        cin >> parent[0][i+2];
    
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            if (parent[j-1][i] == -1) continue;
            parent[j][i] = parent[j-1][parent[j-1][i]];
        }
    }
    for (int i = 0; i < q; i++) { // Queries
        ll x, k;
        cin >> x >> k;
        ll ans = x;
        ll y = 0;
        while (k) {
            if (k&1) {
                ans = parent[y][ans];
            } 
            if (ans == -1) break;
            k /= 2;
            y++;
        }
        cout << ans << "\n";
    }
}
