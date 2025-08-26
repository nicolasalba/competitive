// Find the max sub array that has same freq
// Of elements from 1 to K.
// nums <= 4*10^5
// 1 <= nums[i] <= k, 4*10^5

/*
n:6 k:2
nums:2 2 1 1 2 2
ans: 4
*/

#define bint __int128
ll findMaxFreqSubarray(ll n, ll k, vl nums) {
    bint MOD=212345678987654321LL; // prime
    bint  PI=1e9 + 7; // prime
    vector<bint> pows(k+1, 1);
    for (int i = 0; i < k; i++) {
        pows[i+1] = (pows[i] * PI) % MOD;
    }
    bint oneHash = 0;
    for (int i = 0; i < k; i++) {
        oneHash += pows[i];
        oneHash %= MOD;
    }
    vector<bint> hashes = {0}; // hashes with same freq
    for (int i = 0; i <= n/k; i++) {
        hashes.pb((hashes.back() + oneHash) % MOD);
    }
    map<bint,ll> prefixes;
    prefixes[0] = -1;
    bint actual = 0;

    set<pair<ll,ll>> freqs;
    for (int i = 1; i <= k; i++) {
        freqs.insert({0, i});
    }
    vl cnt(k+1);
    ll ans = 0;
    for (int i =0; i < n; i++) { // n
        freqs.erase({cnt[nums[i]], nums[i]});
        cnt[nums[i]]++;
        freqs.insert({cnt[nums[i]], nums[i]});
        ll mn = freqs.begin()->F;
        actual = (actual + pows[nums[i]-1]) % MOD;
        bint needed = (actual - hashes[mn] + MOD) % MOD;
        if (prefixes.count(needed)) {
            ans = max(ans, i - prefixes[needed]);
        }
        if (prefixes.count(needed)) continue;
        prefixes[needed] = i;
    }
    return ans;
}
