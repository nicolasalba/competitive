struct Block {
    vector<int> depthCnt;
    ll sum = 0;
    void update(int lvl, ll v) { if (lvl >= depthCnt.size()) return; sum += v * depthCnt[lvl]; }
    ll query() { return sum; }
};
struct BlockTree {
    const int SQRT = 320;
    ll n;
    vector<Block> blocks;
    vector<vector<int>> child;
    vector<int> depth, leader, blockId;
    vector<ll> sum;

    BlockTree(ll n, vector<vector<ll>> &adj) : n(n), child(2*n+5), depth(2*n+5), leader(2*n+5), blockId(2*n+5), sum(n) { build(adj); }
    bool is_block(ll x) { return x >= n; }
    void build(vector<vector<ll>> &adj, ll root = 0) {
        auto dfs = [&](ll x, ll p, auto &&dfs) -> void { for (auto y : adj[x]) if (y != p) depth[y] = depth[x]+1, dfs(y, x, dfs); };
        dfs(root, -1, dfs);
        ll idNewBlock = n;
        auto createBlock = [&](int parent, const vector<ll> &nodes) {
            ll id = idNewBlock++;
            if (parent != -1) child[parent].pb(id), depth[id] = depth[parent]+1;
            Block block;
            leader[id] = parent;
            blockId[id] = id;
            block.depthCnt = vector<int>(n);
            auto dfsOverBlock = [&](ll x, auto &&dfsOverBlock) -> void {
                leader[x] = parent;
                blockId[x] = id;
                block.depthCnt[depth[x]]++;
                for (auto y : child[x]) if (!is_block(y)) dfsOverBlock(y, dfsOverBlock); else child[id].pb(y);
            };
            for (auto x : nodes) dfsOverBlock(x, dfsOverBlock);
            blocks.pb(block);
        };
        vector<vector<ll>> byDepth(n);
        for (int i = 0; i < n; i++) byDepth[n-1-depth[i]].pb(i);
        vector<ll> sz(n);
        for (auto &nodes : byDepth) for (int x : nodes) {
            ll blockSz = 0;
            vector<ll> curBlock;
            sz[x] = 1;
            for (int y : adj[x]) if (depth[x] < depth[y]) {
                sz[x] += sz[y];
                blockSz += sz[y];
                curBlock.pb(y);
                if (blockSz > SQRT) createBlock(x, curBlock), sz[x] -= blockSz, blockSz = 0, curBlock.clear();
            }
            child[x].insert(child[x].end(), curBlock.begin(), curBlock.end());
        }
        createBlock(-1, {root});
    }
    void update(int lvl, ll v) { sum[lvl] += v; for (auto &block : blocks) block.update(lvl, v); }
    ll query(ll x) { ll ans = is_block(x) ? blocks[x-n].query() : sum[depth[x]]; for (auto y : child[x]) ans += query(y); return ans; }
};
