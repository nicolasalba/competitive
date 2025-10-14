/* Kruskal O(|edges|*Log|edges|)
   Finds the max/min spanning tree of an undirected graph
   provide the undirected edges with its costs vector<{cost(a, b), a, b}> 
   and the size
*/
struct union_find {
    vl p;
    union_find(int n) : p(n,-1) {}

    ll find(ll x) {
        if (p[x] == -1) return x;
        return p[x] = find(p[x]);
    }

    bool group(ll a, ll b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        p[a] = b;
        return true;
    }
};

ll kruskal(vector<tuple<ll,ll,ll>> &edges, ll nodes) {
    union_find uf(nodes+1);
    sort(all(edges));
    reverse(all(edges)); // for max
    ll answer = 0;
    for (auto edge : edges)  {
        ll cost, a, b;
        tie(cost, a, b) = edge;
        if (uf.group(a, b)) 
            answer += cost;
    }
    return answer;
}
