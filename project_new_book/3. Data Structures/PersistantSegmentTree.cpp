struct Ve {
  Ve *l, *r;
  ll sum;
  Ve(int val) : l(nullptr), r(nullptr), sum(val) {}
  Ve(Ve *l, Ve *r) : l(l), r(r), sum(0) {
    if (l) sum += l->sum;
    if (r) sum += r->sum;
  }
};
Ve* bld(vector<ll>& a, int tl, int tr) {
  if (tl == tr) return new Ve(a[tl]);
  int tm = (tl + tr) / 2;
  return new Ve(bld(a,tl,tm),bld(a,tm+1,tr));
}
ll get_sum(Ve* v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (l == tl && tr == r) return v->sum;
  int tm = (tl + tr) / 2;
  return get_sum(v->l, tl, tm, l, min(r, tm))
        + get_sum(v->r, tm+1, tr, max(l, tm+1), r);
}
Ve* upd(Ve* v,int tl,int tr,int pos,int nv) {
  if (tl == tr) return new Ve(nv);
  int tm = (tl + tr) / 2;
  if (pos <= tm)
    return new Ve(upd(v->l, tl, tm, pos, nv), v->r);
  else
    return new Ve(v->l, upd(v->r, tm+1, tr, pos, nv));
}
Ve* bld(vector<ll> &a) { return bld(a,0,a.size()-1); }
ll get_sum(Ve *v,ll n,int l, int r) { 
  return get_sum(v,0,n-1,l,r); }
Ve* upd(Ve* v,ll n,int pos,int newV) {
  return upd(v,0,n-1,pos,newV); }
Ve* copy(Ve* v) { return new Ve(v->l,v->r); }
