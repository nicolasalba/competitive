// Author: Nicolas Alba
// Practice Every Day :)
// Every day is easier, but you have to practice every day

#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//find_by_order(k) order_of_key(k)

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

// own vector to avoid out bounding with []
template <typename T>
class vector2 : public vector<T> {
    public:
        vector2() : vector<T>() {}
        explicit vector2(int n) : vector<T>(n) {}
        vector2(int n, T value) : vector<T>(n, value) {}
    public:
        T& operator [] (int index) { return this->at(index); }
};


typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<long long, long long, long long> tiii;
typedef pair<long long, long long> pll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector2<int> vi;
typedef vector2<bool> vb;
typedef vector2<ll> vl;
typedef vector2<pll> vpll;
typedef vector2<vl> vvl;
typedef vector2<vi> vvi;
typedef vector2<string> vs;
typedef vector2<ld> vld;

template<class T> using pql = priority_queue<T,vector<T>,greater<T>>;
template<class T> using pqg = priority_queue<T>;


// START DEBUG
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename A> ostream& operator<<(ostream &os, const vector2<vector2<A>> &a) { EACH(x, a) os << "\n" << x; return os; }
template<typename A> ostream& operator<<(ostream &os, const vector<A> &a) { EACH(x, a) os << x << " "; return os; }
template<typename A> ostream& operator<<(ostream &os, const set<A> &a) { EACH(x, a) os << x << " "; return os; }
template<typename A> ostream& operator<<(ostream &os, const unordered_set<A> &a) { EACH(x, a) os << x << " "; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &a) { EACH(x, a) os << x << " "; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const unordered_map<A, B> &a) { EACH(x, a) os << x << " "; return os; }
template<typename A> ostream& operator<<(ostream &os, const pql<A> &a) { pql<A> b = a; while (b.size()) os << b.top() << " ", b.pop(); return os; }
template<typename A> ostream& operator<<(ostream &os, const pqg<A> &a) { pqg<A> b = a; while (b.size()) os << b.top() << " ", b.pop(); return os; }


template <typename... V>
void funcDebug(string vars, V... v) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << v, delim = ", "));
    cout << endl;
}

#ifdef DEBUG_NICO
#define deb(x...) funcDebug(#x, x);
#define LINE  cout << "-------------------" << endl;
#define LINE2 cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
#define LINE3 cout << "-  -  -  -  -  -  -" << endl;
#define debugA(x, n) cout << #x << ": "; for (int zabz = 0; zabz < n; zabz++) cout << (x)[zabz] << " "; cout << endl;
#else
    #define deb(x...)
    #define debugA(x, n)
    #define LINE
    #define LINE2
    #define LINE3
#endif

void cfgIO() {
#ifdef NICOLAS
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
//    freopen("../error.txt", "w", stderr);
#endif
    fastIO();
}
// END DEBUG

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) {
    return uniform_int_distribution<ll>(a, b)(mt_rng);
}

void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
void possible() { cout << "POSSIBLE\n"; }
void impossible() { cout << "IMPOSSIBLE\n"; };

void solve();

const ld DINF=1e100;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const ll infl = INT64_MAX;
const int inf = INT32_MAX;
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1};
const int MOD = 1e9 + 7;

int main() {
    cfgIO();
    int t; cin >> t; while (t--)
        solve();
}

// You can do it
const int N = 2e5 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vvl nums(n, vl(m));
    FOR(i, 0, n) FOR(j, 0, m) cin >> nums[i][j];
    deb(nums);
}
