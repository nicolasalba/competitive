// Shift(A, k), hace shift A(x + k).

// FTT Formula que usaste para Shifts P(x + k)
Si tienes:
C_i = Sum_{j=i to n} f(j) * g(j-i).

l[i] = f(i)
r[i] = g(n-i) // o g(i) y le das reverse.
C_i = (l*r)[n+i]

// Add NTT 
vl fact, ifact;
vl ki, iki;
void initShifts(ll n, ll k) {
    k = (k%MOD + MOD) % MOD;
    fact = ifact = vl(n+1);
    ki = iki = vl(n+1);
    fact[0] = 1;
    ki[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i-1]*i)%MOD;
        ki[i] = (ki[i-1]*k) % MOD;
    }
    ifact[n] = pm(fact[n], MOD-2); // Be careful with this
    iki[n] = pm(ki[n], MOD-2); // This worked with 998244353
    for (int i = n-1; i >= 0; i--) {
        ifact[i] = (ifact[i+1]*(i+1))%MOD;
        iki[i] = (iki[i+1]*k) % MOD;
    }
}

// P(x + k)
vl shift(vl &a, ll k) {
    if (k == 0) return a;
    ll n = a.size();
    initShifts(n, k);
    vl l(n), r(n);
    for (int i = 0; i < n; i++) {
        l[i] = mulmod(a[i], mulmod(fact[i], ki[i]));
        r[i] = ifact[n-1-i];
    }
    vl c = multiply(l,r);
    vl ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = mulmod(c[n-1+i], mulmod(ifact[i], iki[i]));
    }
    return ans;
}

