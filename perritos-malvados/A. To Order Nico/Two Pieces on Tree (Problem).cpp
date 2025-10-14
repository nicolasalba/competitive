// In a tree with 'n' nodes where 2 pieces starting from root 1
// must go to certain nodes each one and must not exceed 'd' between 
// the two pieces, after they have to return to root 1
// two_pieces_on_tree() find the minimum quantity of moves
// My submittion in CF: https://codeforces.com/contest/1774/submission/189071201

ll n, d; // quantity of nodes, maximum distance between pieces
vvl children; // tree
vector<int> a, b; // nodes that must visit first and second piecesS

void dfs(ll x, vl &route) {
    route.pb(x);
    ll kParent = 1; //route
    if (route.size() - 1 >= d) {
        kParent = route[route.size() - 1 - d];
    }
    b[kParent] |= a[x];
    a[kParent] |= b[x];
    each(y, children[x]) {
        dfs(y, route);
        a[x] |= a[y];
        b[x] |= b[y];
    }
    route.pop_back();
}

ll two_pieces_on_tree() {
    ll root = 1;
    vl emptyRoute = vl();
    dfs(root, emptyRoute);
    ll total = 0;
    for (int i = 1; i <= n; i++) {
        total += a[i] + b[i];
    }
    return total * 2 - 4;
}
