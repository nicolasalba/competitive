// https://codeforces.com/contest/7/submission/228366973
// For a string of  5·10^6 with 256 MB.
const long long mod1 = 1000015553, mod2 = 1000028537;
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count()); // Random number generator
static long long base = uniform_int_distribution<int>(356, mod1 - 1)(rng);	// In case TL, use const
// Remember (alfabet < base < mod)
 
struct hash_s{
	string s; 
	long long n;
	vector<long long> hsh1, pwr1;
 
	hash_s() : n(0) {}
	hash_s(string _s) : n(_s.size()), s(_s), hsh1(n), pwr1(n){	
		pwr1[0] = 1;
		for (int i = 1; i < n; i++){
			pwr1[i] = (base * pwr1[i - 1]) % mod1;
		}
		hsh1[0] = s[0];
		for (int i = 1; i < n; i++){
			hsh1[i] = (hsh1[i - 1] * base + (long long)(s[i]))%mod1;
		}
	}
	long long get(int i, int j){ // hash no intervalo [i, j]
		if (i == 0) return (hsh1[j]);
		long long ret1 = ((hsh1[j] - (hsh1[i - 1] * pwr1[j - i + 1])) % mod1 + mod1) % mod1;
		return (ret1);
	}
};
