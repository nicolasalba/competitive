// Josephus Queries (k-esimo eliminado), paso = 2
// O(log n) por query, n hasta 1e9, q hasta 1e5.
// ret (1-index) el k-esimo que se elimina con n ninos
ll kth_del(ll n, ll k){//fist= elim en la 1ra vuelta
  if(n==1) return 1; ll first = (n+1)/2; 
  if(k<=first){ ll x = 2*k;
    return (x<=n ? x : 1);// si n&1 , el ultimo es 1
  } k -= first;
  if(n%2==0){ //quedan odd: 1,3,5,...,n-1  (m = n/2)
    return 2*kth_del(n/2, k) - 1;
  }else{ // quedan: 3,5,7,...,n  (m = n/2)
    return 2*kth_del(n/2, k) + 1;
  } }
