// a^(b^c) mod MOD, MOD prime
// exponent reduced mod (MOD-1)
ll pot(ll a,ll b,ll mod);
ll solve(ll a,ll b,ll c){
  ll e = pot(b,c,MOD-1);  return pot(a,e,MOD);  }