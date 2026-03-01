O(log n), fib(n).F = Fib at n-th position

pair<ll,ll> fib (ll n) {
    if (n == 0) return {0, 1};
    auto p = fib(n >> 1);
    ll c = (p.F * (2*p.S - p.F + MOD)%MOD)%MOD;
    ll d = (p.F * p.F + p.S * p.S)%MOD;
    if (n & 1) return {d, (c + d)%MOD};
    else return {c, d};
}
