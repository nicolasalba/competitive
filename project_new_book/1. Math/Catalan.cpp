// Catalan C_n = C(2n,n)/(n+1) = (2n)!/(n!(n+1)!)
ll catalan(ll n) {
  if (n<0) return 0;
  return mul(fact[2*n],inv(mul(fact[n],fact[n+1]))); }