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
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) >=  (b); (i)--)
#define REP(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
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
typedef vector<pll> vpll;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<ld> vld;
 
template<class T> using pql = priority_queue<T,vector<T>,greater<T>>;
template<class T> using pqg = priority_queue<T>;

const ld DINF=1e100;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const ll infl = INT64_MAX;
const int inf = INT32_MAX;
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1};
const int MOD = 1e9 + 7;
