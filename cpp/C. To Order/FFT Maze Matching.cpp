/*
Finds the shifts of the maze that match with a pattern, even with '?'.
That match with any char.

Pattern and maze n,m <= 400

5 7
qcezchs
hhedywq
wikywqy
qckrqzt
bqexcxz
3 2
??
yw
?q

0000100
0001001
0000000
0000000
0000000
*/
// FFT multiplies polinomial 'a' and 'b' in nlogn
// If TLE, you could change to double. 
#define sz(x) static_cast<int32_t>(x.size())
const int64_t k_II = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int MaxN = 2 * 400 * 400;
 
namespace FFT {
    typedef double num_t;
    struct Complex {
        num_t real, imag;
        Complex(num_t real = 0, num_t imag = 0): real(real), imag(imag) {}
 
        Complex& operator+=(const Complex& o) {
            real += o.real, imag += o.imag; return *this;
        } Complex operator+(const Complex& o) const {
            Complex ret = *this; ret += o; return ret;
        }
 
        Complex& operator-=(const Complex& o) {
            real -= o.real, imag -= o.imag; return *this;
        } Complex operator-(const Complex& o) const {
            Complex ret = *this; ret -= o; return ret;
        }
 
        Complex& operator*=(const num_t& x) {
            real *= x, imag *= x; return *this;
        } Complex operator*(const num_t& x) const {
            Complex ret = *this; ret *= x; return ret;
        }
 
        Complex& operator*=(const Complex& o) {
            tie(real, imag) = make_pair(real * o.real - imag * o.imag, real * o.imag + imag * o.real);
            return *this;
        } Complex operator*(const Complex& o) const {
            Complex ret = *this; ret *= o; return ret;
        }
 
        Complex& operator/=(const num_t& x) {
            real /= x, imag /= x; return *this;
        } Complex operator/(const num_t& x) const {
            Complex ret = *this; ret /= x; return ret;
        }
    };
 
    const num_t PI = acos(num_t(-1));
    const int MAX = 1 << int(ceil(log2(MaxN)) + 1.01);
    static array<int, MAX> bits;
    static array<Complex, MAX> root, iroot;
 
    auto prepare_roots = []() {
        root[1] = iroot[1] = 1;
        for(int len = 2; len < MAX; len *= 2) {
            const Complex w(cos(PI / len), sin(PI / len)), iw(w.real, -w.imag);
            for (int i = len >> 1; i < len; ++i) {
                root[i<<1] = root[i];
                root[i<<1|1] = root[i] * w;
                iroot[i<<1] = iroot[i];
                iroot[i<<1|1] = iroot[i] * iw;
            }
        } return true;
    }();
 
    inline void prepare_cache(int n) {
        static int last = -1;
        if(last == n) return;
        last = n;
        int lg = 0;
        while(1 << (lg + 1) < n) ++lg;
        for(int i = 1; i < n; ++i)
            bits[i] = (bits[i >> 1] >> 1) | ((i & 1) << lg);
    }
 
    void fft(vector<Complex>& a, bool invert) {
        int n = a.size();
        if(n == 1) return;
        for(int i = 1; i < n; i++)
            if(i > bits[i]) swap(a[i], a[bits[i]]);
        const auto& ws = (invert? iroot : root);
        for(int len = 1; len < n; len <<= 1) {
            for(int i = 0; i < n; i += len << 1) {
                for(int j = 0; j < len; j++) {
                    Complex u = a[i + j], v = a[i + j + len] * ws[len + j];
                    a[i + j] = u + v;
                    a[i + j + len] = u - v;
                }
            }
        }
        if(invert)
            for(Complex& x: a) x /= n;
    }
 
    vector<int> multiply(const string& a, const string& b) {
        int n = 1;
        while(n < sz(a) + sz(b)) n <<= 1;
        vector<Complex> fa(n), fb(n);
        for(int i = 0; i < sz(a); i++) {
            if(a[i] != '?') {
                double theta = 2 * PI / 26 * (a[i] - 'a');
                fa[i] = Complex(cos(theta), sin(theta));
            }
        }
        for(int i = 0; i < sz(b); i++) {
            if(b[i] != '?') {
                double theta = - 2 * PI / 26 * (b[i] - 'a');
                fb[i] = Complex(cos(theta), sin(theta));
            }
        }
        prepare_cache(n);
        fft(fa, false); fft(fb, false);
        for(int i = 0; i < n; i++)
            fa[i] *= fb[i];
        fft(fa, true);
        vector<int> result(n);
        for(int i = 0; i < n; i++)
            result[i] = floor(fa[i].real + 0.001); // % MOD;
        // while(!result.empty() && !result.back()) result.pop_back();
        return result;
    }
 
} // namespace FFT

void test_case() {
        int i, j, N, M, r, c;
    cin >> N >> M;
    string s, t;
 
    vector<string> a(N);
    for(auto& x: a) cin >> x;
 
    cin >> r >> c;
 
    int row_reps = ((c + M-1) + M-1) / M;
    int col_reps = ((r + N-1) + N-1) / N;
 
    for(i = 0; i < N; i++) {
        for(j = 0; j < row_reps; j++)
            s += a[i];
    } t = s;
 
    for(i = 0; i < col_reps-1; i++)
        s += t;
 
    t = "";
    for(i = 0; i < r; i++) {
        string x; cin >> x;
        if(i > 0)
            t += string(row_reps * M - c, '?');
        t += x;
    }
    
    reverse(all(t));
    int n = sz(s), m = sz(t);
    auto P = FFT::multiply(s, t);
 
    int reqd = sz(t) - count(all(t), '?');
    vector<string> ans(N, string(M, '0'));
    for(i = 0; i < N; i++)
        for(j = 0; j < M; j++)
            if(m-1 + row_reps * M * i + j < sz(P))
                ans[i][j] += P[m-1 + row_reps * M * i + j] == reqd;
                
    for(auto& x: ans)
        cout << x << '\n';
}
