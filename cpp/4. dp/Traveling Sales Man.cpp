// Given directed weighted graph, gets the minimun halmilton cycle. 
// Use dfs(0, 1), if 1e9 then it impossible, otherwise get the min.
const int MAX_SIZE = 15;
const ll IMPOSSIBLE = 1e9;
ll INITIAL = 0; // initial node
vpl adj[MAX_SIZE];
vvl dp(MAX_SIZE, vl(1 << MAX_SIZE, -1));
ll n, m;
ll target; // init as (1 << n) - 1, full visited

ll dfs(ll x, ll mask) {
    if (dp[x][mask] != -1) {
        return dp[x][mask];
    }
    if (mask == target) {
        each(yy, adj[x]) {
            if (yy.F == INITIAL) {
                return yy.S;
            }
        }
        return dp[x][mask] = IMPOSSIBLE;
    }
    ll ans = IMPOSSIBLE;
    each(yy, adj[x]) {
        ll y, d;
        tie(y, d) = yy;
        if ((mask >> y) & 1) continue;
        ll actual = dfs(y, mask | (1 << y)) + d;
        ans = min(ans, actual);
    }
    return dp[x][mask] = ans;
}
