const int mxn = 2e5;
struct Node { int l=0,r=0; ll sum=0;};//Elem Neutro
int T = 0; // st[0] siempre neutro
Node st[mxn*30]; //!!! Check
struct PST {
  inline int nn(ll s) {
    ++T, st[T] = {0,0,s};
    return T;
  }
  inline int nn(int l, int r) {
    ++T, st[T] = {l,r,0};
    if (l) st[T].sum += st[l].sum;
    if (r) st[T].sum += st[r].sum;
    return T;
  }
  int build(int tl, int tr, vector<ll> &a) {
    if (tl==tr) return nn(a[tr]);
    int m =(tl+tr)>>1;
    return nn(build(tl,m,a),build(m+1,tr,a));
  }
  ll qry(int v, int tl, int tr, int l, int r) {
    if (!v || r < tl || tr < l) return 0;
    if (l <= tl && tr <= r) return st[v].sum;
    int tm = (tl+tr)>>1;
    return qry(st[v].l,tl,tm,l,r)
          +qry(st[v].r,tm+1,tr,l,r);
  }
  int upd(int v, int tl, int tr, int pos, ll val) {
    if (tl ==tr) return nn(val);
    int tm = (tl+tr)>>1;
    if (pos<=tm)
      return nn(upd(st[v].l,tl,tm,pos,val),st[v].r);
    return nn(st[v].l, upd(st[v].r, tm+1,tr,pos,val));
  }
  int build(vector<ll> &a) { 
    return build(0,(int)a.size()-1,a); 
  }
  ll query(int v,int n, int l, int r) {
    return qry(v,0,n-1,l,r);
  }
  int upd(int v, int n, int pos, int val) {
    return upd(v,0,n-1,pos,val);
  }
  int copy(int v) { return v; }
};
