// BlockTree (sqrt on trees). Cambia SOLO:
//  1) Block::add/update/query  (info por bloque)
//  2) BlockTree::update/query  (como acumulas respuesta)
const int SQ=320;
struct Block{ // info del bloque
  int p=0,c[SQ+5]{}; ll s=0; // lvl parent, cnt, sum
  inline void add(int dep){
    if(dep<p) return; dep-=p;
    if(dep<=SQ) c[dep]++;
  }
  inline void upd(int lvl,ll v){
    if(lvl<p) return; lvl-=p;
    if(0<=lvl && lvl<=SQ) s+=v*(ll)c[lvl];
  }
  inline ll qry()const{return s;}
};

struct BT{
  int n; vector<Block> B;
  vector<vi> ch; vi dep; vector<ll> sum; // sum[lvl]
  BT(int N, vector<vi>&a):n(N),ch(N+SQ+5),dep(N+SQ+5){
    B.reserve(SQ+10); build(a,0); }
  inline bool isb(int x)const{return x>=n;}
  void build(vector<vi>&a,int rt){
    auto dfs=[&](int x,int p,auto&&dfs)->void{// depth
      for(int y:a[x]) if(y!=p) 
        dep[y]=dep[x]+1,dfs(y,x,dfs);
    }; dfs(rt,-1,dfs);
    int md=0; for(int i=0;i<n;i++) md=max(md,dep[i]);
    sum.assign(md+1,0);
    vi cnt(md+1),pref(md+2),ord(n); // counting sort
    for(int i=0;i<n;i++) cnt[dep[i]]++;
    for(int d=0;d<=md;d++) pref[d+1]=pref[d]+cnt[d];
    for(int i=0;i<n;i++) ord[pref[dep[i]]++]=i;
    int nb=n; // block creation
    auto mk=[&](int par, const vi&nds){
      int id=nb++; 
      if(par!=-1) ch[par].pb(id),dep[id]=dep[par]+1;
      Block bl; bl.p=dep[id];
      auto go=[&](int x,auto&&go)->void{
        bl.add(dep[x]);
        for(int y:ch[x]) if(!isb(y)) go(y,go); 
                         else ch[id].pb(y);
      };
      for(int x:nds) go(x,go);
      B.pb(bl);
    };
    vi sz(n);
    for(int it=n-1; it>=0; --it){
      int x=ord[it], bs=0; vi cur; cur.reserve(SQ+5);
      sz[x]=1;
      for(int y:a[x]) if(dep[x]<dep[y]){
        sz[x]+=sz[y]; bs+=sz[y]; cur.pb(y);
        if(bs>SQ)
          { mk(x,cur); sz[x]-=bs; bs=0; cur.clear(); }}
      ch[x].insert(ch[x].end(),all(cur)); }}

  // --- DEPENDE DEL PROBLEMA ---
  inline void upd(int lvl,ll v){
    if(lvl<0||lvl>=(int)sum.size()) return;
    sum[lvl]+=v; for(auto&b:B) b.upd(lvl,v);
  }
  ll qry(int x){ // DFS sobre block-tree
    ll ans = isb(x)? B[x-n].qry() : sum[dep[x]];
    for(int y:ch[x]) ans+=qry(y);
    return ans; } // lca no tested 
  int lca(int a,int b){ if(a<0||b<0) return -1;
  while(jmp[a]!=jmp[b]){if(depth[a]>depth[b]) a=jmp[a];
  else b=jmp[b];} while(a!=b){ if(depth[a]>depth[b]) 
    a=par[a]; else b=par[b]; } return a; }};