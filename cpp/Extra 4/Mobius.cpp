const int mxN = 1e6 + 10;
vl lp(mxN);
vl mo(mxN);
void init() { // O(nlogn)
    // lp[1] = 1; // Check if needed
    for (int i = 2;i<mxN;i++) {
        if (!lp[i]) {
            for (int j = i;j<mxN;j+=i) {
                if (!lp[j]) lp[j] = i;
            }
        }
    }

    mo[1] = 1;
    for (int i=2;i<mxN;i++) {
       if (lp[i/lp[i]] == lp[i]) mo[i] = 0;
       else mo[i] = -1*mo[i/lp[i]];
    }
}

/*
 unit(n) = [ n == 1 ]
 unit(n) = sum_{ d divides n } moebius(d)
 
 mobius(1) = 1
 mobius(prime) = -1
 mobius(quantity of primes odd) = -1
 mobius(quantity of primes even) = 1
 mobius(num has a square prime) = 0
*/ 
