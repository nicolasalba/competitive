1. Segment Tree

const int N = 1e6 + 1;

int tree[N * 4 + 4];
int nums[N + 1];

void build(int i, int l, int r) {
	if (l == r) {
		tree[i] = nums[r];
	} else {
		int mid = (l + r) / 2;
		build(i * 2 + 1, l, mid);
		build(i * 2 + 2, mid + 1, r);
		tree[i] = tree[i * 2 + 1] + tree[i * 2 + 2];
		// tree[i] = compare(tree[i * 2 + 1], tree[i * 2 + 2]);
	}
}

void update(int i, int l, int r, int pos, int diff) {
	if (l <= pos && pos <= r) {
		if (l == r) { // leaf
			tree[i] += diff;
		} else { // node
			int mid = (l + r) / 2;
			update(i * 2 + 1, l, mid, pos, diff);
			update(i * 2 + 2, mid + 1, r, pos, diff);
			tree[i] = tree[i * 2 + 1] + tree[i * 2 + 2];
			// tree[i] = compare(...)
		}
	}
}

int query(int i, int sl, int sr, int l, int r) {
	if (l <= sl && sr <= r) { // overlap
		return tree[i];
	} else if (sr < l || r < sl) { // no overlap
		return 0;
	} else { // partially over lap
		int mid = (sl + sr) / 2;
		return query(i * 2 + 1, sl, mid, l, r) + query(i * 2 + 2, mid + 1, sr, l, r);
		// return compare(a, b);
	}
}
