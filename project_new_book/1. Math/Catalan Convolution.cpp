// Catalan with k fixed opens (Ballot formula)
// # ways to complete to valid parentheses
// C(2n+k,n)*(k+1)/(n+k+1)
ll catalanCov(ll n, ll k) {
    ll up = mul(cnk(2*n+k,n),(k+1)%MOD);
    return mul(up,inv((n+k+1)%MOD));
}
//count valid parentheses of total size n with prefix p
ll countParenthesisWithPrefix(ll n, string &p) {
    if (n&1) return 0;
    ll k = 0;
    for (auto c : p) {
        k += (c=='(' ? 1 : -1);
        if (k<0) return 0;
    }
    n=(n-(ll)p.size()-k)/2;
    return catalanCov(n,k);
}
