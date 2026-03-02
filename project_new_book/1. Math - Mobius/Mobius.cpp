/*Mobius μ(n)
μ(1)=1 , μ(n)=0 if square prime divides n
μ(n)=(-1)^{#primes} otherwise
Key identity: ∑_{d|n} μ(d) = [n==1] */
const int mxN = 1e5 + 10;
vl mo(mxN);
void init() { // Call init() first !!!
  mo[1] = 1;
  for (int i=1;i<mxN;i++) 
    for (int j=i+i;j<mxN;j+=i) mo[j]-=mo[i];
}
const int mxN = 1e6 + 10;
vl sv(mxN),primes,mo(mxN); 
void init() { 
  // sv[1] = 1; // Check if needed
  for (int i = 2;i<mxN;i++) { // Linear Sieve
    if (sv[i]==0) { sv[i]=i; primes.pb(i); }
    for (int j=0;j<primes.size()&&primes[j]*i<mxN;j++){
      sv[primes[j]*i] = primes[j];
      if (primes[j] == sv[i]) break;
    }
  }
  mo[1] = 1; // Mobius
  for (int i=2;i<mxN;i++) {
    if (sv[i/sv[i]] == sv[i]) mo[i] = 0;
    else mo[i] = -1*mo[i/sv[i]];
  }
}