// O(log(max(a, b)))
int lcm(int a, int b) {
	return a/gcd(a, b) * b;
}