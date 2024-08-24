const int mxN = 1e6 + 10;
vl sv(mxN); // if prime sv[i]==i, it stores the lowest prime
vl primes;
void init() { // O(n)
    for (int i = 2;i<mxN;i++) {
        if (sv[i]==0) {
            sv[i]=i;
            primes.pb(i);
        }
        for (int j = 0;j<primes.size() && primes[j]*i<mxN;j++) {
            sv[primes[j]*i] = primes[j];
            if (primes[j] == sv[i]) break;
        }
    }
}

// factorization using linear sieve, O(prime_count(n)), n < mxN
void fact(map<ll,int> &f, ll num) {
    while (num>1) {
        ll p = sv[num];
        while (num % p == 0) num/=p, f[p]++;
    }
}
