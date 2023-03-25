// Practice Every Day :)
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define sortt(x) sort(all(x))
#define sortn(x, n) sort((x), (x) + (n))
#define sq(a) ((a) * (a))
#define MP make_pair

#define each(x, xs)  for (auto &x : (xs))
#define rep(i, be, en) for (__typeof(en) i = (be) - ((be) > (en)); i != (en) - ((be) > (en)); i += 1 - 2 * ((be) > (en)))
// old loops
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >=  (b); (i)--)
#define REP(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define EACH(a, x)   for (auto &(a) : (x))

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using ti = tuple<long long, long long, long long>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vs = vector<string>;
using vvl = vector<vl>;
using vpl = vector<pl>;
template<class T> using pql = priority_queue<T,vector<T>,greater<T>>;
template<class T> using pqg = priority_queue<T>;

// >>>>>>>>>> debugging >>>>>>>>>>
#ifdef DEBUG_NICO
#include "debug.h"
#define LINE  cout << "-------------------" << endl;
#else
#define deb(x...)
#define LINE
#endif
// <<<<<<<<<< debugging <<<<<<<<<<

void cfgIO() {
#ifdef NICOLAS
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
//    freopen("../error.txt", "w", stderr);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
// END DEBUG

void solve();
void init();

int testId = 0;
int main() {
    cfgIO();
    init();
//    int t; cin >> t; while (t--)
//        cout << "Case #" << ++testId << ": ",
    solve(), ++testId;
}
const int N = 1e5 + 10;

void init(){}

void solve() {}
