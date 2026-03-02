/* For getting the primes less than mxN in O(mxN)*/
const int mxN = 1e6 + 10;
vl primes, sv(mxN); // lowest prime of i
void init() { // O(n)
  for (int i = 2;i<mxN;i++) {
    if (sv[i]==0) { sv[i]=i; primes.pb(i); }
    for(int j=0;j<primes.size()&&primes[j]*i<mxN;j++) {
      sv[primes[j]*i] = primes[j];
      if (primes[j]==sv[i])break;
    }
  }
}
void fact(map<ll,int> &f,ll x){//O(p_count(n)), n<mxN!!
  while (x>1){ll p=sv[x]; while(x%p==0)x/=p,f[p]++; } }