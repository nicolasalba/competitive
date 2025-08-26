ll cost(vector<ll> &state) {
    //...
}

ld acceptance(ll actualCost, ll costNext, ld temperature) {
    if (costNext < actualCost) return 1;
    return exp((actualCost-costNext)/temperature);
}
 
  
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// also for ll exists mt19937_64
ll randint(ll a, ll b) {
    return uniform_int_distribution<ll>(a, b)(rng);
}
 
ld random_double() {
    return uniform_real_distribution<ld>()(rng);
}
 
 
vector<ll> neighbor(vector<ll> &state) {
    vector<ll> next = state;
    int a = randint(0, n-1);
    int b = randint(0, n-2);
    if (a == b) b++;
    swap(next[a], next[b]);
    return next;
}
 
ld temperature(ld time) {
    return 1-time;
}
 
void test_case() {
    // Init random state
    vector<ll> state = vector<ll>(n);
    shuffle(all(state), rng);
    
    auto actualCost = cost(state);
    auto bestState = state;
    auto bestCost = actualCost;
 
    //Init Temperature
    ld t = 1;
    ld cold_rate = 0.9999;
 
    while (clock() < 0.9*CLOCKS_PER_SEC) {
        t = temperature(clock()/(0.9*CLOCKS_PER_SEC));
        // t *= cold_rate;
        //if (t <= 0) break;
 
        auto next = neighbor(state);
        ll costNext = cost(next);
        if (costNext < bestCost) {
            bestState = next;
            bestCost = costNext;
        }
 
        if (acceptance(actualCost, costNext, t) >= random_double()) {
            state = next;
            actualCost = costNext;
        }
    }
    cout << bestCost << "\n";
}
 
