struct node {
    int next[alpha], end;
    // link -> back-edge, exit -> super link, 
    // cnt -> saber para conteo de posibles n*sqrt(n)
    int link = 0, exit = 0, cnt; // para aho corasick
    int& operator [] (int i) { return next[i]; }
};
vector<node> trie = {node()};
void add_str(string &s, int id = 1) {
    int u = 0;
    for (auto ch : s) {
        int c = ch-L;
        if (!trie[u][c]) {
            trie[u][c] = trie.size();
            trie.pb(node());
        }
        u = trie[u][c];
    }
    trie[u].end = id;
}
void build_ac() {
    queue<int> q; q.push(0);
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int c = 0; c < alpha; ++c) {
            int v = trie[u][c];
            if (!v) trie[u][c] = trie[trie[u].link][c];
            else q.push(v);
            if (!u || !v) continue;
            trie[v].link = trie[trie[u].link][c];
            trie[v].exit = trie[trie[v].link].end ? 
              trie[v].link : trie[trie[v].link].exit;
            trie[v].cnt += trie[trie[v].link].cnt;
        }
    }
}
void run_ac(string &s) {
    int u = 0, sz = s.size();
    for (int i = 0; i < sz; ++i) {
        int c = s[i]-L;
        while (u && !trie[u][c]) u = trie[u].link;
        u = trie[u][c];
        int x = u;
        while (x) {
            int id = trie[x].end;
            if (id) cnt[id-1]++; // end y superlink
            x = trie[x].exit;
        }
    }
}