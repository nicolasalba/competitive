#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define sortt(x) sort(all(x))
#define sq(a) ((a) * (a))
 
#define each(x, xs)  for (auto &x : (xs))
#define rep(i, be, en) for (__typeof(en) i = (be) - ((be) > (en)); i != (en) - ((be) > (en)); i += 1 - 2 * ((be) > (en)))
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
 
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
#ifdef NICO_LOCAL
    // #include "debug.h"
    #define LINE cerr << "-------------------" << endl;
#else
    #define deb(x...)
    #define LINE
#endif
// <<<<<<<<<< debugging <<<<<<<<<<
 
void test_case();

 
const ll INF = INT64_MAX;
const int inf = INT32_MAX;
const ld PI = acos(-1);

const int DX[4]{1,0,-1,0}, DY[4]{0,1,0,-1};
 
int testId;

void init();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int T;
    T = 1;
    // cin >> T;
    rep (t, 0, T) { testId++; test_case(); }
 
    return 0;
}

void init() {
    
}

#define ll long long
// const int MOD = 1e9+7;
const int MOD = 1e9 + 7;
#define poly vector<ll>
typedef int tp;
#define fore(i,a,b) for (int i =a, ThxDem=b;i<ThxDem;i++)

ll sum(ll x, ll y) {
    ll ans = (x + y) % MOD;
    if (ans < 0) ans += MOD;
    return ans;
}

ll mult( ll x, ll y) {
    ll ans = (x % MOD) * (y%MOD);
    ans %= MOD;
    if (ans < 0) ans += MOD;
    return ans;
}

#define add(n,s,d,k) fore(i,0,n)(d)[i]=sum((d)[i], mult((s)[i],k))
tp * ini(int n) { tp * r= new tp[n]; fill(r,r+n,0); return r;}
void karatsura(int n, tp* p, tp* q, tp*r) {
    if (n<=0) return;
    if (n<35) fore(i,0,n) fore(j,0,n)r[i+j]=sum(r[i+j],mult(p[i],q[j]));
    else {
        int nac=n/2, nbd=n-n/2;
        tp *a=p, *b=p+nac, *c=q, *d=q+nac;
        tp *ab=ini(nbd+1), *cd=ini(nbd+1),
        *ac=ini(nac*2),*bd=ini(nbd*2);
        add(nac,a,ab,1);add(nbd,b,ab,1);
        add(nac,c,cd,1);add(nbd,d,cd,1);
        karatsura(nac,a,c,ac);karatsura(nbd,b,d,bd);
        add(nac*2,ac,r+nac,-1);add(nbd*2,bd,r+nac,-1);
        add(nac*2,ac,r,1);add(nbd*2,bd,r+nac*2,1);
        karatsura(nbd+1,ab,cd,r+nac);
        free(ab);free(cd);free(ac);free(bd);
    }
}


void test_case() {
    
}
