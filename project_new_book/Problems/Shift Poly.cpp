// ADD ntt, or karatsuba.
// A poly: c_0 + c_1*x + c_2*x^2 + ... is transformed to
// c_0 + c_1*(x+k) + c_)*(x+k)^2 + ...

vl fact, ifact;
vl ki, iki;
void initShifts(ll n, ll k) {
    k = (k%MOD + MOD) % MOD;
    fact = ifact = vl(n+1);
    ki = iki = vl(n+1);
    fact[0] = ifact[0] = 1;
    ki[0] = iki[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i-1]*i)%MOD;
        ifact[i] = inv(fact[i]);
        ki[i] = (ki[i-1]*k) % MOD;
        iki[i] = inv(ki[i]);
    }
}
 
// P(x + k)
vl shift(vl &a, ll k) {
    if (k == 0) return a;
    ll n = a.size();
    initShifts(n, k);
    vl l(n), r(n);
    for (int i = 0; i < n; i++) {
        l[i] = mulmod(a[i], fact[i]);
        r[i] = mulmod(ki[n-1-i], ifact[n-1-i]);
    }
    vl c = multiply(l,r);
    vl ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = mulmod(c[n-1+i], ifact[i]);
    }
    return ans;
}
