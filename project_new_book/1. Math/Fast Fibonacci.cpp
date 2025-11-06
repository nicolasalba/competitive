// Fast Fibonacci O(log n)
// Use fib(n).F to get the at nth position
pair<ll,ll> fib (ll n) {
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    ll c = (p.F * (2*p.S - p.F + MOD)%MOD)%MOD;
    ll d = (p.F * p.F + p.S * p.S)%MOD;
    if (n & 1)
        return {d, (c + d)%MOD};
    else
        return {c, d};
}
/* Fib properties
Addition Rule: F_n+k = F_k * F_n+1 + F_k-1 * F_n
F_2n= Fn * (F_n+1 + F_n-1)

GCD Identity: GCD(F_m,F_n) = F_gcd(m,n)
Cassinis' identity: F_n-1 * F_n+1 - F_n*F_n = (-1)^n
*/
