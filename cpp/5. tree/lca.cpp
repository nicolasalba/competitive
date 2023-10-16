#include<bits/stdc++.h>
//#include<cmath>
//#include<bitset>
 
using namespace std;
 
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define sortt(x) sort(all(x))
#define sortn(x, n) sort((x), (x) + (n));
#define SQ(a) ((a) * (a))
#define max3(a, b, c) max((a), max((b), (c)))
#define max4(a, b, c, d) max(max3(a, b, c), d)
#define min3(a, b, c) min((a), min((b), (c)))
#define min4(a, b, c, d) min(min3(a, b, c), d)
#define fastIO() cin.tie(0); ios::sync_with_stdio(0);
 
// loops
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 
#define ROF(i, a, b) for (int (i) = (a); (i) >=  (b); (i)--)
#define REP(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define EACH(a, x)   for (auto &(a) : (x))

typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<long long, long long, long long> tiii;
typedef pair<long long, long long> pll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<string> vs; 
 
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1};
const int MOD = 1e9 + 7;
 
template <typename... V>
void funcDebug(string vars, V... v) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << v, delim = ", "));
    cout << endl;
}
 
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    #define deb(x...) funcDebug(#x, x);
    #define debug(x) (cout << #x << ": " << x << endl);
    #define LINE  cout << "-------------------" << endl;
    #define LINE2 cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    #define LINE3 cout << "-  -  -  -  -  -  -" << endl;
    #define debugA(x, n) cout << #x << ": "; for (int zabz = 0; zabz < n; zabz++) cout << (x)[zabz] << " "; cout << endl;
    #define debugI(x) cout << #x << ": "; EACH(y, (x)) cout << y << " "; cout << endl;
#else
    #define deb(x...)
    #define debug(x)
    #define debugA(x, n) 
    #define LINE
    #define LINE2
    #define LINE3
    #define debugI(x) 
#endif
 
const ll infl = INT64_MAX;
const int inf = INT32_MAX;


// const int N = 1e5 + 10;

// const int LOG = 16;


const int N = 50000;
const int LOG = 16;

vector<pii> children[N];
int up[N][LOG];
int dist[N][LOG];
int depth[N];
bool visited[N];


void dfs(int x, int level = 0) {
    if (visited[x]) return;
    visited[x] = true;
    depth[x] = level;
    EACH(y, children[x]) {
        if (!visited[y.F]) {
            up[y.F][0] = x;
            dist[y.F][0] = y.S;
            dfs(y.F, level + 1);
        }
    }
}

int query(int x, int y) {
    if (depth[y] > depth[x]) swap(x, y);
    int toUp = depth[x] - depth[y];
    int bit = 0;
    int res = 0;
    while (toUp) {
        if (toUp & 1) res += dist[x][bit], x = up[x][bit];
        bit++;
        toUp >>=1;
    }
    if (x == y) return res;
    ROF(i, LOG - 1, 0) {
        if (up[x][i] != up[y][i]) {
            res += dist[x][i] + dist[y][i];
            x = up[x][i];
            y = up[y][i];
        }
    }
    return dist[x][0] + dist[y][0] + res;
}

void solve() {
    int n;
    cin >> n;
    FOR(i, 0, n - 1) {
        int a, b, w;
        cin >> a >> b >> w;
        children[a].PB({b, w});
        children[b].PB({a, w});
    }
    int root = 0;
    dfs(root);
    FOR(i, 1, LOG) {
        FOR(j, 0, n) {
            int ancestor = up[j][i - 1];
            up[j][i] = up[ancestor][i - 1];
            dist[j][i] = dist[ancestor][i - 1] + dist[j][i - 1];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << query(a, b) << "\n";
    }
}   


int main() {
    fastIO();
    solve();
}
