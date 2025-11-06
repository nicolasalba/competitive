// !!! Add centroid Descomposition
// When you can get Answers for fixed root
// When you can get answer for all paths for fixed root
struct centroid_data {
    ll idx = 0, best_red = -1;

    void mark_red(int x, ll d) {
        if (best_red==-1) best_red = d;
        best_red = min(best_red, d);
    }

    int query(int x, ll d) {
        if (best_red == -1) return inf;
        return best_red + d;
    }
};

vector<vector<pair<ll,ll>>> belongs; // idx centroid, extra data, init this!!
vector<centroid_data> centroids;

int id_centroid = 0;

void process_centroid(int root, int sz) { // creates centroids
    centroids.push_back({id_centroid++, -1});
    auto & c = centroids.back();

    auto dfs = [&](int x, int p, ll dist, auto &&dfs) -> void {
        belongs[x].pb({c.idx, dist});
        for (auto & y : adj[x]) if (y != p && alive[y])
            dfs(y, x, dist+1, dfs);
    };

    dfs(root, -1, 0, dfs);
}

void mark_red(int x) { // UPDATE O(log n) centroids belongs to node
    for (auto [idx, dist] : belongs[x])
        centroids[idx].mark_red(x, dist);
}

int query(int x) { // iterates over each centroid belongs to node O(logn)
    int best = 1e9; 
    for (auto [idx, dist] : belongs[x])
        best = min(best, centroids[idx].query(x, dist));
    return best;
}

