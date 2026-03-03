static const int A = 26;
//#define has(p,c) (st[p].nxt.count(c)==1) para map<int
#define has(p,c) (st[p].nxt[c] != -1)
struct SAM {
  struct St { int link,len; array<int,A> nxt;ll occ,dp;
    bool cl; int fst; St(){ nxt.fill(-1);
                 link=-1;len=0;occ=dp=0;cl=0;fst=-1;}};
  vector<St> st; int last, sz;
  vector<vector<int>> inv;
  SAM(int n) { init(n); }
  void init(int n){ 
    st.assign(2*n+2,St());
    st[0]=St(); st[0].link=-1; last=0; sz=1; }
  void add(int c){ // extend SAM with char c
    int cur = sz++;
    st[cur].len=st[last].len+1; st[cur].occ = 1;
    st[cur].fst=st[cur].len-1; st[cur].cl = 0;
    int p = last;
    while(p!=-1 && !has(p,c)) 
      { st[p].nxt[c]=cur; p=st[p].link; }
    if(p == -1) st[cur].link = 0;
    else {
      int q = st[p].nxt[c];
      if(st[p].len + 1 == st[q].len){
        st[cur].link = q;
      } else {
        int cl=sz++; st[cl]=st[q];
        st[cl].len=st[p].len+1;
        st[cl].occ=0; // clone NO cuenta
        st[cl].cl = true;
        while(p != -1 && st[p].nxt[c] == q)
          { st[p].nxt[c] = cl; p = st[p].link; }
        st[q].link = st[cur].link = cl; } }
    last = cur; }
  vector<int> order(int n){ // creciente por len
    vector<int> cnt(n+1,0), ord(sz);
    for(int i=0;i<sz;i++) cnt[st[i].len]++;
    for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
    for(int i=sz-1;i>=0;i--) ord[--cnt[st[i].len]] = i;
    return ord; }
  void build(const string& s) {
    init((int)s.size());
    for(char ch: s) add(ch - 'a');
    auto ord = order((int)s.size());
    for(int i=sz-1;i>0;i--){  // occ (endpos sizes)
      int v = ord[i], p = st[v].link;
      if(p!=-1) st[p].occ += st[v].occ;
    }
    // dp[v] = sum_{v->u} (occ[u] + dp[u])
    for(int i=sz-1;i>=0;i--){
      int v = ord[i];  ll sum = 0;
      for(int c=0;c<A;c++){
        if (!has(v,c)) continue;
        int u=st[v].nxt[c]; sum +=st[u].occ+st[u].dp;
      }
      st[v].dp = sum;
    }
    inv.assign(sz,{}); // Para patrones
    for(int v=1;v<sz;v++) inv[st[v].link].pb(v); }
  string kth(long long k){
    string ans; int v = 0;
    while(true){
      for(int c=0;c<A;c++){
        if(!has(v,c)) continue;
        int u = st[v].nxt[c];
        ll block = st[u].occ + st[u].dp;
        if(k > block){ k -= block; continue; }
        ans.pb(char('a'+c));
        if(k <= st[u].occ) return ans;
        k -= st[u].occ;
        v = u;
        break; } } } 
  int walk(const string &p) {
    int v=0;
    for(char ch:p) {
      int c=ch-'a'; if(!has(v,c)) return -1;
      v=st[v].nxt[c]; }
    return v; }
  int first_occ(const string& p){
    int v=walk(p);  // 0-index
    if (v==-1) return -1;
    return st[v].fst - (int)p.size() + 1; }
  ll distinc() {
    ll ans=0;
    for(int i=1;i<sz;i++) 
      ans+=st[i].len-st[st[i].link].len;
    return ans; }
  void dfsocc(int v, int L, vector<int> &res) {
    if (!st[v].cl) res.pb(st[v].fst-L+1);
    for (auto & u : inv[v]) dfsocc(u,L,res); }
  vector<int> occs(const string &p) {
    ll x = walk(p); if (x==-1) return {};
    vector<int> ans; dfsocc(x,p.size(),ans);
    return ans; } 
  vector<int> vis; int timer = 1;
  ll matches_cyclic(string p){//occ of all cyclicshft p
    vis.resize(sz);
    int L=p.size(); p+=p; ll ans=0; ++timer;
    for(int x=0,l=0; char ch: p){
      int c=ch-'a';
      while(x!=-1&&!has(x,c))
        x=st[x].link, l=(x<0?0:st[x].len);
      if(x<0){ x=0; l=0; continue; }
      x=st[x].nxt[c]; if(++l>st[x].len) l=st[x].len;
      if(l>=L){
        int v=x;
        while(st[st[v].link].len>=L) v=st[v].link;
        if(vis[v]!=timer) vis[v]=timer, ans+=st[v].occ;
      } }
    return ans; } };