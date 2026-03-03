// sprime.count_primes(n);
// O(n^(2/3))
// PI(n): tuned for n up to around 1e13.
struct count_primers_struct{
 vector<int>pr,mn; ll ans,y;
 vector<pair<pair<ll,int>,char>>qs;
 ll count_primes(ll n){ y=pow(n,0.64); if(n<100)y=n;
  pr.clear(); mn.assign(y+1,-1); ans=0;
  for(int i=2;i<=y;++i){ 
    if(mn[i]==-1){ mn[i]=pr.size(); pr.push_back(i); }
    for(int k=0,sz=pr.size();k<sz;++k){
      int p=pr[k]; if(1LL*i*p>y)break; mn[i*p]=k;
      if(i%p==0)break;
    } }
  if(n<100)return pr.size(); ll s=n/y;
  for(int p:pr){ if(p>s)break; ++ans; }
  int ssz=ans; int ptr=pr.size()-1;
  for(int i=ssz,sz=pr.size();i<sz;++i){
    while(ptr>=i&&1LL*pr[i]*pr[ptr]>n)--ptr;
    if(ptr<i)break; ans-=ptr-i+1; }
  phi(n,ssz-1); sort(qs.begin(),qs.end());
  int ind=2,sz=pr.size(); fenwick fw(sz);
  for(const auto&qq:qs){
    ll v=qq.first.first; int a=qq.first.second;
    char sgn=qq.second;
    while(ind<=v)fw.add(sz-1-mn[ind++],1);
    ans+=(fw.ask(sz-a-2)+1)*sgn;
  } qs.clear();
  return ans-1; }
 void phi(ll n,int a,int s=1){
  if(!n)return;
  if(a==-1){ ans+=n*s; return; }
  if(n<=y){ qs.emplace_back(make_pair(n,a),s);
    return; }
  phi(n,a-1,s); phi(n/pr[a],a-1,-s); }
 struct fenwick{
  vector<int>tr; int n; fenwick(int n=0):n(n){
  tr.assign(n,0); }
  void add(int i,int k){for(;i<n;i=i|(i+1))tr[i]+=k;}
  int ask(int r){int res=0;
   for(;r>=0;r=(r&(r+1))-1)res+=tr[r]; return res;}};};
count_primers_struct sprime;
