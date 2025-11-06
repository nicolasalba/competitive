vector<vector<ll>> adj;
vector<bool> alive;
vector<int> sz;


void init(int n) {
    alive = vector<bool>(n+1, true);
    sz = vector<int>(n+1);
    adj = vector<vector<ll>>(n+1);
    // belongs = vector<vector<pair<ll,ll>>>(n+1); // !! for online
}

int get_sz(int x, int p) {
    sz[x] = 1;
    for (auto y : adj[x]) if (y != p && alive[y]) 
        sz[x] += get_sz(y, x);
    return sz[x];
}

int find_centroid(int x, int p, int tree_sz) {
    for (auto y : adj[x]) if (y != p && alive[y]) {
        if (sz[y] * 2 > tree_sz) {
            return find_centroid(y, x, tree_sz);
        }
    }
    return x;
}

//!!! Implement O(sz) solution, use adj, only use alive nodes check with alive[x]
// dont sz[x] because it is not rerooted to centroid
void process_centroid(int root, int sz); 

void centroid_decomp(ll x) {
    int sz = get_sz(x, -1);
    int centroid = find_centroid(x, -1, sz);

    process_centroid(centroid, sz); // implement!!!
    alive[centroid] = false;

    for (auto y : adj[centroid]) if (alive[y]) {
        centroid_decomp(y);
    }
}

