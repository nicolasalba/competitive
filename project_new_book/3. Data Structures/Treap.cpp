/* ITreap tp(n+5); tp.bld(s);
tp.rev(a,b); tp.cut(a,b); // 1-indexed */
struct ITreap{
  struct N{int l,r,sz;unsigned p;char c;bool rv;};
  vector<N> t; int T=0,rt=0; unsigned rg=712367;
  ITreap(int mx=1):t(mx+1){}
  unsigned rnd(){ 
      rg^=rg<<13; rg^=rg>>17; rg^=rg<<5; return rg; }
  int sz(int x){ return x?t[x].sz:0; }
  void pl(int x){ t[x].sz=1+sz(t[x].l)+sz(t[x].r); }
  void ap(int x){ if(!x)return; t[x].rv^=1; 
    swap(t[x].l,t[x].r); }
  void ps(int x){ if(!x||!t[x].rv)return; 
    ap(t[x].l); ap(t[x].r); t[x].rv=0; }
  int nn(char c){ t[++T]={0,0,1,rnd(),c,0}; return T; }
  void spl(int x,int &a,int &b,int k){
    if(!x){a=b=0; return;} ps(x);
    if(sz(t[x].l)>=k) 
      spl(t[x].l,a,t[x].l,k), b=x, pl(b);
    else spl(t[x].r,t[x].r,b,k-sz(t[x].l)-1),a=x,pl(a);
  }
  int mrg(int a,int b){
    if(!a||!b) return a?a:b;
    if(t[a].p>t[b].p){ ps(a); 
      t[a].r=mrg(t[a].r,b); pl(a); return a; }
    ps(b); t[b].l=mrg(a,t[b].l); pl(b); return b; }
  void bld(const string& s){ 
    rt=0; for(char c:s) rt=mrg(rt,nn(c)); }
  void cut(int l,int r){
    int A,BC,B,C; spl(rt,A,BC,l-1); spl(BC,B,C,r-l+1);
    rt=mrg(mrg(A,C),B); }
  void rev(int l,int r){
    int A,BC,B,C; spl(rt,A,BC,l-1); spl(BC,B,C,r-l+1);
    ap(B); rt=mrg(A,mrg(B,C)); }
  void dfs(int x,string& o){
    if(!x) return; ps(x); dfs(t[x].l,o);
    o.pb(t[x].c); dfs(t[x].r,o); }
  string str(){ string o; o.reserve(sz(rt)); 
    dfs(rt,o); return o; }
};
