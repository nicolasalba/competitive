#include <bits/stdc++.h>
using namespace std;
 
#define forr(i,a,b) for(int i = int(a); i < int(b); ++i)
#define forn(i, n) forr(i,0,n)
#define dforr(i,a,b) for(int i = int(b)-1; i >= int(a); --i)
#define dforn(i,n) dforr(i,0,n)
#define fore(e,c) for(const auto& e : (c))
#define db(v) cerr<<#v" = "<<(v)<<'\n'
#define nn cout<<'\n'
#define sz(v) (int((v).size()))
#define all(v) begin(v), end(v)
#define pb push_back
#define pp pop_back
#define fst first
#define snd second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
const ll MAXN = 2e5+100;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);
 
using my_clock=chrono::steady_clock;
 
class RandomNumberGenerator{
	mt19937_64 engine;
public:
	RandomNumberGenerator():
		engine(my_clock::now().time_since_epoch().count()){}
	template<class Int=int>
	Int integer(Int n){return integer<Int>(0,n);}
	template<class Int=int>
	Int integer(Int l,Int r){
		return uniform_int_distribution<Int>(l,r-1)(engine);
	}
	template<class Real=double>
	Real real(){return uniform_real_distribution<Real>(0,1)(engine);}
} rng;
 
class TimeKeeper{
	using time_point=my_clock::time_point;
	time_point start=my_clock::now();
public:
	template<class Rep=double,class Period=ratio<1>>
	Rep elapsed(){
		time_point const now=my_clock::now();
		return chrono::duration<Rep,Period>(now-start).count();
	}
} timer;
 
template<class Energy>
class SimulatedAnnealing{
	using stir_fun=function<const Energy()>;
	using save_fun=function<void()>;
	stir_fun stir;
	save_fun save;
	Energy curr_energy,coldest;
	Energy init_state()const{
		Energy const energy=stir();
		return(save(),energy);
	}
	double measure(double const percentage_left)const{
		return percentage_left;
	}
	double accept(Energy const next,double const temp)const{
		double const delta=static_cast<double>(curr_energy-next);
		if(delta>=0){return 1;}
		return exp(delta/temp);
	}
public:
	SimulatedAnnealing(stir_fun _stir,save_fun _save):
		stir{_stir},save{_save},curr_energy{init_state()},coldest{curr_energy}{}
	SimulatedAnnealing&simulate(double const time_limit=1){
		double const start=timer.elapsed();
		for(
			double elapsed=timer.elapsed()-start;
			elapsed<time_limit;
			elapsed=timer.elapsed()-start
		){
			Energy const next=stir();
			coldest=min(coldest,next);
			double const temp=measure(1-elapsed/time_limit);
			if(accept(next,temp)>=rng.real()){curr_energy=(save(),next);}
		}
		return*this;
	}
	Energy peek_last()const{return curr_energy;}
	Energy peek_cold()const{return coldest;}
};
 
int join(vector<vector<bool>>&mat,int const u){
	int const n=sz(mat);
	int ans=0;
	forn(i,n){
		if(i==u){continue;}
		if(!mat[u][i]){continue;}
		forr(j,i+1,n){
			if(j==u){continue;}
			if(!mat[u][j]){continue;}
			if(!mat[i][j]){mat[i][j]=mat[j][i]=true,++ans;}
		}
	}
	return ans;
}
 
void solve() {
	int n,m;
	cin>>n>>m;
	vector<vector<bool>>mat(n,vector<bool>(n));
	forn(j,m){
		int u,v;
		cin>>u>>v,--u,--v;
		mat[u][v]=mat[v][u]=true;
	}
	int const t=n*(n-1)/2;
	if(m==t){
		cout<<"0\n\n";
		return;
	}
	vector<int>order(n);
	iota(all(order),0);
	int x=-1,y=-1;
	auto stir=[&]{
		auto aux=mat;
		x=rng.integer(n);
		y=rng.integer(n-1);
		if(y>=x){++y;}
		int e=m,ans=0;
		swap(order[x],order[y]);
		forn(i,n){
			++ans;
			e+=join(aux,order[i]);
			if(e==t){break;}
		}
		swap(order[x],order[y]);
		return ans;
	};
	auto save=[&]{swap(order[x],order[y]);};
	SimulatedAnnealing<int>sa{stir,save};
	sa.simulate(0.9);
	int const ans=sa.peek_last();
	cout<<ans<<'\n';
	forn(i,ans){
		cout<<order[i]+1;
		if(i!=ans-1){cout<<' ';}
		else{cout<<'\n';}
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	solve();
}
