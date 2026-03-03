//A poly:c0+c1*x+c2*x^2+... becomes
//c0+c1*(x+k)+c2*(x+k)^2+...
vl fact,ifact,ki,iki;
void initShifts(ll n,ll k){
  fact=ifact=ki=iki=vl(n+1); fact[0]=ki[0]=1;
  for(int i=1;i<=n;i++) { fact[i]=mulmod(fact[i-1],i);
    ki[i]=mulmod(ki[i-1],k); }
  ifact[n]=inv(fact[n]);
  for(int i=n;i>0;i--)ifact[i-1]=mulmod(ifact[i],i);
  iki[n]=inv(ki[n]);
  for(int i=n;i>0;i--)iki[i-1]=mulmod(iki[i],k);
}
//P(x+k)
vl shift(vl&a,ll k){
  k=(k%MOD+MOD)%MOD;
  if(!k) return a;
  ll n=a.size(); initShifts(n,k);
  vl l(n),r(n),ans(n);
  for(int i=0;i<n;i++){ l[i]=mulmod(a[i],fact[i]);
    r[i]=mulmod(ki[n-1-i],ifact[n-1-i]); }
  vl c=multiply(l,r);
  for(int i=0;i<n;i++)ans[i]=mulmod(c[n-1+i],ifact[i]);
  return ans;
}
