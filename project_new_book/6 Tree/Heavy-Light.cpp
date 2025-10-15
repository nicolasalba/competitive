vector<vector<int>> adj; // INIT this, use init()!!!
vector<int> parent, depth, heavy, head, pos;
int cur_pos;

int dfs(int v) {
    int size = 1, max_size = 0;
    for (int c : adj[v]) if (c != parent[v]) {
        parent[c] = v, depth[c] = depth[v] + 1;
        int c_size = dfs(c);
        size += c_size;
        if (c_size > max_size)
            max_size = c_size, heavy[v] = c;
    }
    return size;
}

void decompose(int v, int h) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1) // check when copy head and heavy
        decompose(heavy[v], h);

    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c);
    }
}

segtree tree; // !!ADD SegTree
vector<ll> values;
void init() { 
    int n = adj.size();
    parent = depth = head = pos = vector<int>(n);
    heavy = vector<int>(n, -1);
    cur_pos = 0;

    dfs(0);
    decompose(0, 0);
    tree.init(n);
    for (int i = 0;i<n;i++) tree.update(pos[i], { values[i] });
}

int seg_query(int a, int b) {
    return tree.query(a, b).x; // !! depends of segtree
}

void update_query(int node, int val) {
    tree.update(pos[node], { val }); // depends of segtree
}

int query(int a, int b) {
    int res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        int cur_heavy_path_max = seg_query(pos[head[b]], pos[b]);
        res = max(res, cur_heavy_path_max);
    }
    if (depth[a] > depth[b])
        swap(a, b);
    int last_heavy_path_max = seg_query(pos[a], pos[b]); // consider pos[a]+1 when query edges
    res = max(res, last_heavy_path_max); // Change to Segment Tree Operation
    return res;
}
