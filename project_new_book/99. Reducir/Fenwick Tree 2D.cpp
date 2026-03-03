struct BIT2D { // 1-indexed 
  ll lsb(ll i) { return i & -i; }
  ll sum(int x1, int y1, int x2, int y2) {
    return sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)
              +sum(x1-1,y1-1); } };

