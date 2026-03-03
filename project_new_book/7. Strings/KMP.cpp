vector<int> prefix_function(vector<ll> &s) {
  int n = s.size();
  vector<int> pf(n);
  pf[0] = 0;
  for (int i = 1, j = 0; i < n; i++) {
    while (j && s[i] != s[j]) j = pf[j-1];
    if (s[i] == s[j]) j++;
    pf[i] = j;
  }
  return pf;
}