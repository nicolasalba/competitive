vector<int> funz(string &s) {
  int n = s.size(), l =0, r= 0; vi v(n);
    for (int i= 1; i<n; i++) {
      if (i<r) v[i] = min(r-i, v[i-l]);
      while (i+v[i]<n && s[v[i]]==s[i+v[i]]) v[i]++;
      if (i+v[i]>r) l = i, r = i+v[i];
    }
    return v;
}