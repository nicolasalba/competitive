/* Combinatorics with a Prime Module
nCk(n,k) = How many ways you can choose 'k' items from an array of 'n' items with a given prime module.

Use:
 - NCK nck(max N, prime module);
 - nck.nCk(n,k)
*/

struct NCK {
    ll MAX_N;
    ll MOD;
    vl fact;

    explicit NCK(ll maxN, ll mod) : MAX_N(maxN), MOD(mod) {
        fact.resize(MAX_N + 1, 1);
        fact[0] = 1;
        REP(i, 1, MAX_N) {
            fact[i] = fact[i - 1] * (i % MOD);
            fact[i] %= MOD;
        }
    }

    ll inv(ll a){
        return powmod(a, MOD-2); // MOD is prime, otherwise use powmod(a, eulerPhi(mod) - 1)
    }

    ll powmod(ll a, ll b){
        if (b == 0) return 1;
        ll mid = powmod(a, b / 2);
        ll ans = (mid * mid) % MOD;
        if (b & 1) {
            ans *= a;
            ans %= MOD;
        }
        return ans;
    }

    ll nCk(ll n, ll k){ // TODO: add if's when case is zero
        ll nOverK = (fact[n] * inv(fact[k])) % MOD;
        return (nOverK * inv(fact[n-k])) % MOD;
    }
};

