// Given an array A
// calculate: 
// (∑l=0 to (n-1) ∑r=l to (n-1) f(l,r)⋅(r−l+1)) % mod
// f(l,r) = a[l] ^ a[l+1] ^ ... ^ a[r]
// In other words, it calculate the sum
// of xor-subarrays multiplied by its size
// A or nums is 0-indexed
// sum(nums,n,998244353)
const int mod = 998244353;
ll sum(vl &nums, ll n) {
    vector<ll> pref(n+1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] ^ nums[i-1];
    }
    ll ans =0;
    for (ll bit = 0; bit <= 60; bit++) {
        vl cnt(2);
        vl dist(2);
        ll sum = 0;
        for (int i = 0; i <= n; i++) {
            ll actual = (pref[i] >> bit) & 1;
            sum = (sum + dist[!actual]) % mod;
            cnt[actual]++;
            dist[actual] = (dist[actual] + cnt[actual]) % mod;
            dist[!actual] = (dist[!actual] + cnt[!actual]) % mod;
        }
        ans += (((1ll << bit) % mod) * sum) % mod;
        ans %= mod;
    }
    return ans;
}
