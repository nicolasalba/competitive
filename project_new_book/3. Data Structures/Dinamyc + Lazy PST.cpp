const int mxn = 2e5 + 1;
struct Node { int l,r; int mn; int lz; };//lz esde mx
const int E = 2e9; // op(a,b) es de mn
Node st[mxn*450]; // mxn*669->2GB Needed,3 a 6.5 segs
struct PST { 
  int T;
  PST() { st[0] = {0,0,0,0}; T = 0; } // neutro
  inline int cl(int v) { ++T; st[T]=st[v]; return T; }
  int qry(int v,int tl,int tr,int l,int r,int acc=0) {
    if (r<tl||tr<l) return E; if (!v) return acc;
    if (l<=tl && tr<=r) { return max(st[v].mn,acc); }
    acc = max(acc,st[v].lz); int tm = (tl+tr)>>1;
    return min(qry(st[v].l,tl,tm,l,r,acc),
                    qry(st[v].r,tm+1,tr,l,r,acc)); }
  int upd(int v,int tl,int tr, int l, int r, int val) {
    if (r < tl || tr < l) return v;
    if (l <= tl && tr <= r) {
      if (st[v].lz >= val) return v;// Truco Memoria
      int w = cl(v);
      st[w].lz = max(st[w].lz, val);
      st[w].mn = max(st[w].mn, val);
      return w; }
    ll tm = (tl+tr)>>1;
    int L = upd(st[v].l, tl, tm, l, r, val);
    int R = upd(st[v].r, tm+1,tr,l,r,val);
    if (L==st[v].l&& R == st[v].r) return v;//Mem trick
    int w=cl(v); st[w].l=L, st[w].r=R;
    int mnch=min(st[st[w].l].mn, st[st[w].r].mn);
    st[w].mn=max(mnch, st[w].lz);
    return w; }
  int query(int v, int n, int l, int r) {
    return qry(v,0,n-1,l,r); }
  int upd(int v, int n, int l, int r, int val) {
    return upd(v,0,n-1,l, r,val); } };
PST pst;
struct query { int a, b, mx;};
struct segtree { // Segtree over queries
  int n; vector<query> d; vector<int> head,nxt;
  vector<pair<int,int>> lq;
  segtree(int sz_q) : n(sz_q),lq(n,{-1,-1}){
    head.assign(2*n,-1); }
  void add(int idx, const query &q) {
    ll id = d.size(); d.pb(q); nxt.pb(head[idx]);
    head[idx] = id; }
  void addQuery(int l, int r, const query &q) {
    for (l += n, r += n+1; l< r; l >>=1, r>>=1) {
      if (l&1) add(l++,q); if (r&1) add(--r,q); } }
  void dfs(int id,vector<int> &ans,int root, int szn) {
    ll cnt = 0;
    for (int p=head[id]; p!=-1; p=nxt[p]) {
      root=pst.upd(root,szn,d[p].a,d[p].b,d[p].mx); }
    if (id<n) dfs(id*2,ans,root,szn), 
              dfs(id*2+1,ans,root,szn);
    else if(lq[id-n].F != -1 ){ auto & [a,b]=lq[id-n];
      ans[id-n]=pst.query(root,szn,a,b); } }
  vector<int> solve(int nsz, int sz) {
    vector<int> ans(nsz); int root = 0;
    dfs(1,ans,root,sz); return ans; } };
