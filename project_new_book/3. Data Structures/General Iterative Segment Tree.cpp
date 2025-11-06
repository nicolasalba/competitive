const int inf = 1e9;
// >>>>>>>>> Implement
struct Node { ll mn = inf, mx = -inf; };

Node e() { return Node(); } // op(a, e()) = a
 
Node op(const Node &a, const Node &b) { // asociative property
    Node c;
    c.mn = min(a.mn, b.mn);
    c.mx = max(a.mx, b.mx);
    return c;
}
// <<<<<<<
 
struct segtree { 
    vector<Node> t;
    ll n;
 
    void init(int n) {
        t.assign(n * 2, e());
        this->n = n;
    }
 
    void init(vector<Node>& s) {
        n = s.size();
        t.assign(n * 2, e());
        for (int i = 0; i < n; i++) t[i+n] = s[i];
        build();
    }
 
    void build() {  // build the tree
        for (int i = n - 1; i > 0; --i) t[i] = op(t[i*2], t[i*2+1]);
    }
 
    // set value at position p
    void update(int p, const Node& value) {
        for (t[p += n] = value; p >>= 1; ) t[p] = op(t[p*2], t[p*2+1]);
    }
 
    // sum on interval [l, r]
    Node query(int l, int r) {
        r++; // make this inclusive
        Node resl=e(), resr=e(); // null element
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) resl = op(resl, t[l++]);
            if (r&1) resr = op(t[--r], resr);
        }
        return op(resl, resr);
    }
 
    Node get(int i) {
        return t[i+n];
    }
    
    // Maximum r that satisfy g(op(t[l], t[l+1], ..., t[r-1])) = True
    // if there's no g() that returns true, then r = l
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= n);
        assert(f(e()));
        if (l == n) return n;
        ll size = n;
        l += size;
        Node sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, t[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, t[l]))) {
                        sm = op(sm, t[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, t[l]);
            l++;
        } while ((l & -l) != l);
        return n;
    }

    // If g is monotone, this is the minimum l that satisfies 
    // g(op(a[l], a[l + 1], ..., a[r - 1])) = true.
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= n);
        assert(f(e()));
        if (r == 0) return 0;
        ll size = n;
        r += size;
        Node sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(t[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(t[r], sm))) {
                        sm = op(t[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(t[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
};
