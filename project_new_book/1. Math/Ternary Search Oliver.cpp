ll ternary_search(ll l, ll r){ // Max version
  while(r - l > 3) {
    ll m1 = (l+r)/2; ll m2 = (l+r)/2 + 1;
    ll f1 = f(m1), f2 = f(m2);   
    //if(f1 > f2) l = m1;
    if (f1 < f2) l = m1;
    else r = m2; }
  ll ans = 0;
  for(int i = l; i <= r; i++){
    ll tmp = f(i);
    ans = max(ans, tmp); /*ans = min(ans, tmp);*/
  } return ans; }
//Faster version - 300 iteratons up to 1e-6 precision 
double ternary_search(double l, double r,int No = 300){
    while(r - l > EPS){ // for(int i = 0; i < No; i++){
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (f(m1) < f(m2)) l = m1;// if (f(m1) > f(m2))
        else r = m2;
    } return f(l); }
//for max version, for min change the signals 