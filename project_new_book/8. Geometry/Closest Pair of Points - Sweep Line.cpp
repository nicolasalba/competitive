#define x first
#define y second
 
ll dist2(pair<int,int> a, pair<int,int> b) {
    return 1LL * (a.x-b.x)*(a.x-b.x) + 1ll* (a.y-b.y)*(a.y-b.y);
}

pair<pair<ll,ll>,pair<ll,ll>> ClosestPair(vector<pair<int, int>> pts) {
    int n = pts.size();
    sort(pts.begin(), pts.end());
    set<pair<ll, ll>> s;

    long long best_dist = 8e18;
    int last_best = 0; // if you need the points
    int j = 0;
    for (int i = 0; i < n; ++i) {
        ll d = ceil(sqrtl(best_dist));
        while (pts[i].first - pts[j].first >= d) {
            s.erase({pts[j].second, pts[j].first});
            j += 1;
        }

        auto it1 = s.lower_bound({pts[i].second - d, pts[i].first});
        auto it2 = s.upper_bound({pts[i].second + d, pts[i].first});
        
        for (auto it = it1; it != it2; ++it) {
            ll dx = pts[i].first - it->second;
            ll dy = pts[i].second - it->first;
            ll distance = 1LL * dx * dx + 1LL * dy * dy;
            if (distance <= best_dist) { // must be <= otherwise got WA
                best_dist = distance;
                last_best = i; // if you need the points
            }    
        } 
        s.insert({pts[i].second, pts[i].first}); 
    }

    // If you need the points otherwise return best_dist;
    for (int i = 0; i < last_best; i++) {
        if (dist2(pts[i],pts[last_best])==best_dist) {
            return {pts[i],pts[last_best]};
        }
    }
    assert(false);
    return {{0,0},{0,0}};
}
 
void test_case() {
    ll n;
    cin >> n;
    vector<pair<int,int>> points(n);
    for (int i =0;i<n;i++) {
        ll x, y;
        cin >> x >> y;
        points[i] ={x,y};
    }
    auto ans = ClosestPair(points);
    cout << dist2(ans.F, ans.S) << "\n";
}

// AC https://cses.fi/problemset/task/2194/
