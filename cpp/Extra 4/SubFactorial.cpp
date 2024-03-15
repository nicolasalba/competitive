/* Denote as !n or derangement numbers
  Count the number of permutations where no element is in
  the originial position, formally p[i] != i
  
  it can be seen as f(n) = n!-sum_i=1_to_n { cnk(n,i)*f(n-i) } 
  f(0)=1, f(1) = 1
  
  1 0 1	2 9 44 265 1,854 14,833 133,496	
  
  n! = sumi=0,i<=n,{cnk(n,i)!i}
*/
const int mxN = 2e6 + 10;
ll add(ll x, ll y) { return (x+y)%MOD; }
ll mul(ll x, ll y) { return (x*y)%MOD; }
vl subFact(mxN);
void init() {
    subFact[0] = 1;
    subFact[1] = 0;
    for (int i = 2;i<mxN;i++) {
        subFact[i] = mul(add(subFact[i-1],subFact[i-2]),i-1);
    }
}
