// FFT trick for auto-correlation:
// ans[i] = sum_j a[j]*a[j+i]
auto b = actual; reverse(all(b));
auto conv = multiply(actual, b); // FFT/NTT
int m = actual.size();
answer[0] = conv[m-1];
for(int i=1;i<m;i++)
  answer[i] = conv[m-1-i]+conv[2*(m-1)-i+1];