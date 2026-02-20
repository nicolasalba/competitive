/*
Catalan Convolution.

Convolution for k=3
((( A ) B ) C ) D

Where A + B + C + D = N, for N + 1
*/

ll cnk(ll n, ll k);

// for parethesis example
// number of n+k pairs having k open parethesis at beginning

// (cnk(2n+k,n)*(k+1))/(n+k+1)
ll catalanCov(ll n, ll k) {
    ll up = mul(cnk(2*n+k,n),(k+1)%MOD);
    ll down = (n+k+1)%MOD;
    return mul(up,inv(down));
}

/*
6
(()

ans: 2
*/
// size, and prefix
ll countParenthesisWithPrefix(ll n, string &p) {
    if (n&1) return 0;
    ll k = 0;
    for (auto c : p) {
        if (c=='(') k++;
        else k--;
        if (k<0) return 0;
    }
    n=(n-(ll)p.size()-k)/2;
    return catalanCov(n,k);
}
