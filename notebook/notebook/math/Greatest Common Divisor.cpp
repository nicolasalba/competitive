// Alternative: __gcd(a, b);
// O(log(max(a, b)))

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}