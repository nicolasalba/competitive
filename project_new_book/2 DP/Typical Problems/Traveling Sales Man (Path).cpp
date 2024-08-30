// Given directed weighted graph, gets the minimun halmilton path.
ll n;
vvl adj;
 
int dp[1<<20][20];
ll f(ll mask, ll x) {
    if (dp[mask][x] != -1) {
        return dp[mask][x];
    }
    if (x == n-1) {
        return (mask == 0);
    }
    ll ways = 0;
    for (auto y : adj[x]) {
        if ((mask>>y)&1) {
            ways = (ways + f(mask^(1<<y), y)) % MOD;
        }
    }
    return dp[mask][x] = ways;
}
 
void test_case() {
    ll m;
    cin >> n >> m;
    adj.assign(n,vl());
    memset(dp,-1,sizeof dp);
    for (int i=0;i<m;i++) {
        ll x, y;
        cin >>x >> y;
        x--,y--;
        adj[x].pb(y);
    }
    cout << f((1<<n)-1-1,0) << "\n";
}