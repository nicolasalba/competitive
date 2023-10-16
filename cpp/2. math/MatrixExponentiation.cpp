// For Linear recurenses DP in O(log(N)*M^3)

typedef ll T;
const int M = 2;
struct Matrix {
    T a[M][M] = {0};
    Matrix() {}

    Matrix (vector<vector<T>> o) {
        for (int i = 0; i < M; i++) 
            for (int j = 0; j < M; j++)
                a[i][j] = o[i][j];
    }

    Matrix operator * (const Matrix &o) {
        Matrix ans;
        for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
        for (int k = 0; k < M; k++)
            ans.a[i][j] += a[i][k] * o.a[k][j]
            //,ans.a[i][j] %= MOD
            ;
        return ans;
    }
};

Matrix matrixPower(Matrix a, ll power) {
    Matrix ans;
    for (int i = 0; i < M; i++) ans.a[i][i] = 1;

    while (power) {
        if (power & 1) {
            ans = ans * a;
        }

        a = a * a;
        power >>= 1;
    }

    return ans;
}

void test_case() {
    ll n;
    cin >> n;
    Matrix m({
        {1, 1},
        {1, 0}
    });

    auto ans = matrixPower(m, n);
    cout << ans.a[0][1] << "\n";
}
