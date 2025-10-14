// Multiplicative Function
// Calc f(n), f(n) = sum_{1 to n} n / gcd(n,i)

// f(p) = (p-1)*p + 1
// f(p^k) = f(p^(k-1)) + p^k*p^(k-1)*(p-1)

const int mxN = ll(1e7) + 10;
vl lp(mxN); // least prime factor
vl pw(mxN); // power of least prime factor
vl fn(mxN); // answer of f(n)
vl primes;

void init() { // O(n), Call init first !!!!
    fn[1] = pw[1] = lp[1] = 1;
    for (ll i = 2;i<mxN;i++) {
        if (lp[i] == 0) {
            lp[i] = pw[i] = i;
            fn[i] = (i-1)*i + 1;
            primes.pb(i);
        }

        for (auto p : primes) {
            ll j = i*p;
            if (j >= mxN) break;
            if (lp[i] != p) {
                lp[j] = pw[j] = p;
                fn[j] = fn[i] * fn[p];
            } else { 
                lp[j] = p;
                pw[j] = pw[i] * p;
                ll fk = fn[pw[i]] + pw[j] * pw[i] * (p-1);
                fn[j] = fn[i/pw[i]] * fk;
                break;
            }
        }
    }
}