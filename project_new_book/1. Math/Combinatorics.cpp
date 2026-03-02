ll nck(ll n, ll k) { // O(min(n, n-k)) lineal
  if (k < 0 || n < k) return 0;
  k = min(k,n-k); ll ans = 1;
  for (int i=1; i<=k; i++) ans = ans * (n-i+1) / i;
  return ans;
}
