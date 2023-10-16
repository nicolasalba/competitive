Modular Aritmethics.cpp


ll sum(ll a, ll b) {
    ll c = a + b;
    if (c >= m) c -=m;
    return c;
}

ll sub(ll a, ll b) {
    ll c = a - b;
    if (c < 0) c += m;
    return c;
}

ll mul(__int128 a, __int128 b) {
    return (a * b) % m;
}

ll modexp(ll a, ll n) {
    if (n == 0) return 1;
    ll p = modexp(a, n / 2);
    ll res = mul(p, p);
    if (n & 1) {
        res = mul(res, a);
    }
    return res;
}

// O(sqrt n)
ll phi(ll n) {
    ll ans = n;
    for (int p = 2; p <= n/p; ++p) {
        if (n % p == 0) ans -= ans / p;
        while (n % p == 0) n /= p;
    }
    if (n > 1) ans -= ans / n;
    return ans;
}

ll x, y;
/// O(log(max(a, b)))
ll euclid(ll a, ll b) {
    if(b == 0) { x = 1; y = 0; return a; }
    ll d = euclid(b, a%b);
    ll aux = x;
    x = y;
    y = aux - a/b*y;
    return d;
}

ll invmod(ll a) {
    ll d = euclid(a, m);
    if (d > 1) return -1;
    return (x % m + m) % m;
}

ll divv(ll a, ll b) {
    ll inv = invmod(b);
    if (inv == -1) return -1;
    ll res = mul(a, inv);
    return res;
}


// a * (b^{euler(m) - 1})
// for primes: a * b ^ (P - 2)
ll divv2(ll a, ll b) {
    if (__gcd(b, m) != 1) return -1;
    ll ex = modexp(b, euler - 1);
    ll res = mul(a, ex);
    return res;
}