// Calc a^b^c % MOD
// MOD is prime

ll pot(ll x, ll y, ll mod);
 
void test_case() {
    ll a, b, c;
    cin >> a >> b >> c;
    // fermat theorem
    // a^(p-1) = 1 (mod p)
    b = pou(b, c, MOD - 1);
    a = pou(a, b, MOD);
    cout << a << "\n";
}
