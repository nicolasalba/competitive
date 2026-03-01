#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(s) int(s.size())
#define RB(x) (x<n?r[x]:0)
void csort(vector<int> &sa, vector<int> &r, int k){
	int n=SZ(sa);
	vector<int> f(max(255,n+1)),t(n);
	fore(i,0,n) f[RB(i+k)]++;
	int sum=0;
	fore(i,0,max(255,n+1))f[i]=(sum+=f[i])-f[i];
	fore(i,0,n)t[f[RB(sa[i]+k)]++]=sa[i];
	sa=t;
}
 
vector<int> constructSA(vector<int> &s){
	int n=SZ(s),rank;
	vector<int> sa(n),r(n),t(n);
	fore(i,0,n)sa[i]=i,r[i]=s[i];
	for(int k=1;k<n;k*=2){
		csort(sa,r,k);csort(sa,r,0);
		t[sa[0]]=rank=0;
		fore(i,1,n){
			if(r[sa[i]]!=r[sa[i-1]]||RB(sa[i]+k)!=RB(sa[i-1]+k))rank++;
			t[sa[i]]=rank;
		}
		r=t;
		if(r[sa[n-1]]==n-1)break;
	}
	return sa;
}
 
vector<int> computeLCP(vector<int> &s, vector<int> &sa){
	int n=SZ(s),L=0;
	vector<int> lcp(n),plcp(n),phi(n);
	phi[sa[0]]=-1;
	fore(i,1,n)phi[sa[i]]=sa[i-1];
	fore(i,0,n){
		if(phi[i]<0){plcp[i]=0;continue;}
		while(s[i+L]==s[phi[i]+L])L++;
		plcp[i]=L;
		L=max(L-1,0);
	}
	fore(i,0,n)lcp[i]=plcp[sa[i]];
	return lcp;
}


void test_case() { // max element <= n
    ll n; cin >> n; vector<int> nums(n); 
    for (int i =0;i<n;i++) cin >> nums[i];
    nums.pb(0); // min element 
    auto sa = constructSA(nums);
    auto lcp = computeLCP(nums, sa); // lpc[i] = lcp(sa[i-1],sa[i])
    sa.erase(sa.begin());
    lcp.erase(lcp.begin());
    nums.pop_back();
}
    
