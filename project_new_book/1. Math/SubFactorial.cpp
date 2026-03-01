const int mxN = 2e6 + 10; vector<ll> subFact(mxN);
void init() {
  subFact[0] = 1, subFact[1] = 0;
  for (int i = 2;i<mxN;i++)
    subFact[i]=mul(add(subFact[i-1],subFact[i-2]),i-1);
}
