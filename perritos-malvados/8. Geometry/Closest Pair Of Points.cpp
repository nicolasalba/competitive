// It seems O(n log n), not sure but it worked for 50000
// This algorithms is not the best, TLE in CSES
// https://cses.fi/problemset/task/2194

#define x first
#define y second
long long dist2(pair<int, int> a, pair<int, int> b) {
	return 1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y);
}
pair<int, int> closest_pair(vector<pair<int, int>> a) {
	int n = a.size();
	assert(n >= 2);
	vector<pair<pair<int, int>, int>> p(n);
	for (int i = 0; i < n; i++) p[i] = {a[i], i};
	sort(p.begin(), p.end());
	int l = 0, r = 2;
	long long ans = dist2(p[0].x, p[1].x);
	pair<int, int> ret = {p[0].y, p[1].y};
	while (r < n) {
		while (l < r && 1LL * (p[r].x.x - p[l].x.x) * (p[r].x.x - p[l].x.x) >= ans) l++;
		for (int i = l; i < r; i++) {
			long long nw = dist2(p[i].x, p[r].x);
			if (nw < ans) {
				ans = nw;
				ret = {p[i].y, p[r].y};
			}
		}
		r++;
	}
	return ret;
}

// Tested: https://vjudge.net/solution/52922194/ccPUXODAMWTzpzCEvXbV
void test_case() {
    ll n;
    cin >> n;
    vector<pair<int,int>> points(n);
    for (int i = 0;i<n;i++) cin >> points[i].x >> points[i].y;
    auto ans = closest_pair(points);
    cout << fixed << setprecision(6);
    if (ans.F > ans.S) swap(ans.F,ans.S);
    ld dist = sqrtl(dist2(points[ans.F],points[ans.S]));
    cout << ans.F << " " << ans.S << " " << dist << endl;
}

