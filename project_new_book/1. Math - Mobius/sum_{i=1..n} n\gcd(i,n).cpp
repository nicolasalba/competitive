/* f(n) = Σ_{i=1..n} n/gcd(n,i)
Multiplicative func.
f(p) = (p-1)p + 1
f(p^k) = f(p^{k-1}) + p^k p^{k-1}(p-1)  */
// O(n) linear sieve
const int MX = 1e7+10;
vector<ll> lp(MX), pw(MX), f(MX), primes;
void init(){
  f[1]=lp[1]=pw[1]=1;
  for(int i=2;i<MX;i++){
    if(!lp[i]) {
      lp[i]=pw[i]=i; f[i]=(ll)(i-1)*i+1; primes.pb(i);
    }
    for(int p:primes){
      ll j=1LL*i*p;
      if(j>=MX) break;
      if(p!=lp[i]) { lp[j]=pw[j]=p; f[j]=f[i]*f[p]; }
      else{
        lp[j]=p; pw[j]=pw[i]*p;
        ll fp = f[pw[i]] + pw[j]*pw[i]*(p-1);
        f[j]=f[i/pw[i]]*fp; break;
      } } } }