// Counts pairs gcd(i,j) == k
// 1 <= i <= a, 1 <= j <= b, where (1,2) equals to (2,1)
// Call Mobius First !!!
// O(min(a,b)/K)
// Tested: https://vjudge.net/problem/HDU-1695
ll solve(ll a, ll b, ll k) {
    if (k==0) return 0;
    a/=k;
    b/=k;
    if (a > b) swap(a,b);
    if (a == 0) return 0;
    ll ans = 0;
    for (ll d = 1; d <= a; d++) {
        ans += (a/d) * (b/d) * mo[d];
    }
    ll sub = 0; // Substracting equals, e.g. (1,2) to (2,1)
    for (ll d = 1;d <= a; d++) {
        sub += (a/d)*(a/d) * mo[d];
    }
    ans-=(sub-1)/2;
    return ans;
}
