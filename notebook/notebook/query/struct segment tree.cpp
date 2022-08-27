// Segment Tree for Sum in ranges, also gives you the quantity of numbers greater than zero (present numbers)

// segtree tree;
// tree.init(N);
// update values
// uses queries

struct segtree { 
    int n;
    vl sum;
    vl present;

    void init(int nn) {
        sum.clear();
        present.clear();
        n = nn;
        int size = 1;
        while (size < n) {
            size *= 2;
        }
        sum.resize(size * 2);
        present.resize(size * 2);
    }

    void update(int i, int sl, int sr, int pos, ll diff) {
        if (sl <= pos && pos <= sr) {
            if (sl == sr) {
                sum[i] += diff;
                present[i] = sum[i] > 0;
            } else {
                int mid = (sl + sr) / 2;
                update(i * 2 + 1, sl, mid, pos, diff);
                update(i * 2 + 2, mid + 1, sr, pos, diff);
                sum[i] = sum[i * 2 + 1] + sum[i * 2 + 2];
                present[i] = present[i * 2 + 1] + present[i * 2 + 2];
            }
        }
    }

    void update(int pos, ll diff) {
        update(0, 0, n - 1, pos, diff);
    }

    pll query(int i, int sl, int sr, int l, int r) {
        if (l <= sl && sr <= r) {
            return {sum[i], present[i]};
        } else if(sr < l || r < sl) {
            return {0, 0};
        } else {
            int mid = (sl + sr) / 2;
            auto a = query(i * 2 + 1, sl, mid, l, r);
            auto b = query(i * 2 + 2, mid + 1, sr, l, r);
            return {a.F + b.F, a.S + b.S};
        }
    }

    pll query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};
