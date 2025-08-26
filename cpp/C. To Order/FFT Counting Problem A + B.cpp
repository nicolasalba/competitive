// Given an array A of len N<= 1e5
// with numbers between [-50000, 50000]
// Count the number of ways to A_i + A_j = A_k
// i,j,k are distinct. 
// 1,2,3 is a different way than 3,1,2
const int N = 50000; // max N

// This seems to be very optimzed
// Maybe it could work with one frequency array
// Adding an constant to avoid negatives
void test_case() {
    ll n;
    cin >> n;
    vl cnt(N+1), cnt2(N+1);
    ll zeros = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (x == 0) zeros++;
        else if (x > 0) {
            cnt[x]++;
        } else {
            cnt2[-x]++;
        }
    }
    ll total = 0;
    vl pos = multiply(cnt, cnt);
    vl neg = multiply(cnt2, cnt2);
    reverse(all(cnt2));
    vl mix = multiply(cnt, cnt2);
    if (zeros >= 3) {
        total += (zeros) * (zeros-1) * (zeros-2);
        // triple zeros
    }
    reverse(all(cnt2));
    for (int i = 1; i <= N; i++) {
        // (ways to get pos[i]) = cnt[i]
        total += pos[i] * cnt[i];
        total += neg[i] * cnt2[i];
        if (i % 2 == 0) {
            // num + num = 2num, same indice
            total -= cnt[i/2] * cnt[i]; 
            total -= cnt2[i/2] * cnt2[i];
        }
    }
    for (int i = 1; i <= N; i++) {
        if (cnt[i] >= 2) {
            // num + 0 = num
            total += zeros * cnt[i] * (cnt[i]-1) * 2;
        }
        if (cnt2[i] >= 2) {
            total += zeros * cnt2[i] * (cnt2[i]-1)*2;
        }
    }
    for (int i = 0; i <= 2*N; i++) {
        if (i == N) {
            // num - num = 0
            total += mix[N] * zeros * 2;
        } else if (i < N) {
            // num - num2 = num3 (num3 negativo)
            total += mix[i] * cnt2[N-i] * 2;
        } else {
            // num - num2 = num3 (num3 positivo)
            total += mix[i] * cnt[i-N] * 2;
        }
    }
    cout << total << "\n";

}

