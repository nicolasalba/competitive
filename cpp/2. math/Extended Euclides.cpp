// It finds X and Y in equation:
// a * X + b * Y = gcd(a, b)

int x, y;

int euclid(int a, int b) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int aux = x;
	x = y;
	y = aux - a/b*y;
	return euclid(b, a % b);
}