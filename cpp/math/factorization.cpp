// Polar rho, miller rabin
// O(log^3(n))
// But I get TLE once in 1e7
ll expmod(ll b, ll e, ll m) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = (1ll*ans*b) % m;
        b = (1ll*b*b) % m;
        e /= 2;
    }
    return ans;
}

ll mulmod(ll a, ll b, ll m) {
    ll r = a*b-(ll)((long double)a*b/m+.5)*m;
    return r < 0 ? r+m : r;
}

/// O(log^3(n))
bool test(ll n, int a) {
    if (n == a) return true;
    ll s = 0, d = n-1;
    while (d%2 == 0) s++, d /= 2;
    ll x = expmod(a, d, n);
    if (x == 1 || x+1 == n) return true;
    for (int i = 0; i < s-1; i++) {
        x = mulmod(x, x, n);
        if (x == 1) return false;
        if (x+1 == n) return true;
    }
    return false;
}

ll gcd(ll a, ll b) { return a ? gcd(b%a, a) : b; }

ll rho(ll n) {
    if (!(n&1)) return 2;
    ll x = 2, y = 2, d = 1;
    ll c = rand() % n + 1;
    while (d == 1) {
        x = (mulmod(x, x, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        d = gcd(abs(x-y), n);
    }
    return d == n ? rho(n) : d;
}

bool is_prime(ll n) {
    if (n == 1) return false;
    int ar[] = {2,3,5,7,11,13,17,19,23};
    for (auto &p : ar) if (!test(n, p)) return false;
    return true;
}

/// O(log(n)^3) aprox
void fact(ll n, map<ll, int> &f) {
    if (n == 1) return;
    if (is_prime(n)) { f[n]++; return; }
    ll q = rho(n);
    fact(q, f); fact(n/q, f);
}

// ############################################################
// Normal algorithm with precomputing primes 
// O(sqrt(MAX_N)/log(sqrt(MAX_N)), it worked for 1e9 for me
const ll MAX_N = 1e7;
vl primes;
void init() {
    ll N = sqrt(MAX_N) + 1;
    vector<bool> sieve(N + 1);
    for (ll i = 2; i <= N; i++) {
        if (!sieve[i]) {
            for (ll j = i*i; j <= N; j+=i) {
                sieve[j] = true;
            }
        }
    }
    for (ll i = 2; i <= N; i++) {
        if (!sieve[i]) primes.pb(i);
    }
}
 
vl fact(ll n) {
    vl ans;
    ll rest = n;
    for (auto &p : primes) {
        if (p * p > n) break;
        if (rest % p == 0) {
            ans.pb(p);
            while (rest % p == 0) rest/=p;
        }
    }
    if (rest != 1) {
        ans.pb(rest);
    }
    return ans;
}

// ###################################################
// Modification of sieve erathostenes
// From CF Faster than previous, but needs more memory
const int N = int(1e7) + 5;
int mind[N];
void init() {
    for (int i = 0; i < N; i++)
		mind[i] = i;
	
	for (int p = 2; p < N; p++) {
		if (mind[p] != p)
			continue;
		for (int d = 2 * p; d < N; d += p)
			mind[d] = min(mind[d], p);
	}
}

vector<int> getPrimes(int v) {
	vector<int> ps;
	while (v > 1) {
		if (ps.empty() || ps.back() != mind[v])
			ps.push_back(mind[v]);
		v /= mind[v];
	}
	return ps;
}


