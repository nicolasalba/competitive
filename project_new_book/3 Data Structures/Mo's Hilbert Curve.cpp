/*
Hilbert Curve for Mo's, 

This is a better ordering for Mo (review Mo's algorithm), 
sometimes it take the half time, other times it takes
more time. So it needs a revision to identify when it's better!!!
https://codeforces.com/blog/entry/61203
*/

inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

struct Query {
	int l, r, idx;
	int64_t ord;
 
	inline void calcOrder() {
		ord = gilbertOrder(l, r, 21, 0); // n,q <= 1e5
	}
};

inline bool operator<(const Query &a, const Query &b) {
	return a.ord < b.ord;
}