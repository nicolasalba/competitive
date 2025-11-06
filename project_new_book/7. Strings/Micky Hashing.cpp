ll pot(ll x, ll y, ll m) {
    if (y==0) return 1;
    ll ans = pot(x,y/2,m);
    ans = (ans*ans)%m;
    if (y&1) ans = (ans*x)%m;
    return ans;
}
 
struct Hash {
    int p = 997, m[2], in[2];
    vl h[2],inv[2];
    Hash(string s) {
        m[0] = 998244353, m[1]=1e9+9;
        for (int i = 0;i<2;i++) {
            in[i] = pot(p,m[i]-2,m[i]);
            h[i].resize(s.size()+1);
            inv[i].resize(s.size()+1);
            ll acu = 1;
            h[i][0]=0,inv[i][0]=1;
            for (int j = 0;j<s.size();j++) {
                h[i][j+1]=(h[i][j]+acu*s[j])%m[i];
                inv[i][j+1]=(1ll*inv[i][j]*in[i])%m[i];
                acu = (acu * p) % m[i];
            }
        }
    }
 
    ll get(int b, int e) {
        e++;
        ll ha[2];
        for (int i =0;i<2;i++) {
			ha[i] = ((((h[i][e] - h[i][b]) * (ll)inv[i][b]) % m[i]) + m[i]) % m[i];        
        }
        return ((ha[0]<<32)|ha[1]);
    }
};
