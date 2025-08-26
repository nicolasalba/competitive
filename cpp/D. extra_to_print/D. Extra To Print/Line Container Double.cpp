// Same as Line Container but for double, and special case with the index.
struct Line {
	mutable ld k, m, p;
        ll idx; // for having index aditionally
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ld x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ld inf = 1/.0;

	ld div(ld a, ld b) { // floored division
		return a / b; }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ld k, ld m, ll idx) {
		auto z = insert({k, m, 0, idx}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ld query(ld x, ll idx) {
		assert(!empty());
		auto it = lower_bound(x);
                if (idx == it->idx) {
                    // if you need especial case with the index
                    //return -1;
                }
                auto l = *it;
		return l.k * x + l.m;
	}
};
