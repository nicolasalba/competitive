// user getDivisors to get all divisors of a number in aprox O(n^(1/3))
// Add  fact method of factorization, miller rabin one.

void iterate(ll num, ll idx, vector<pair<ll,ll>> &facts, vector<ll> &divs) {
    if (idx == facts.size()) {
        divs.pb(num);
        return;
    }
    iterate(num, idx+1, facts, divs);
    ll f = 1;
    for (int i = 0; i < facts[idx].S; i++) {
        f *= facts[idx].F;
        iterate(num * f, idx + 1, facts, divs);
    }
}

// n^(1/3)
vector<ll> getDivisors(ll n) {
    map<ll,int> f;
    fact(n, f);
    vector<pair<ll,ll>> facts;
    for (auto p : f) facts.pb({p.F, p.S});
    vl divs;
    iterate(1, 0, facts,divs);
    return divs;
}
