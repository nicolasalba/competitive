/*Catalan, counts the number of ways of:
( A ) B, where |A|+|B| = N, for N+1
*/

ll catalan(ll n) {
    if (n<0) return 0;
    ll up = fact[2*n];
    ll down = mul(fact[n],fact[n+1]);
    return mul(up,inv(down));
}
