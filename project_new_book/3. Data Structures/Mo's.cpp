// For mxn 1e5=310, for 2e5=430 
const int BLOCK_SIZE = 430; 
struct query {
  int l, r, idx;
  bool operator <(query &other) const {
    return MP(l / BLOCK_SIZE, r) < 
            MP(other.l / BLOCK_SIZE, other.r);
  }
};
void add(int); void remove(int); ll getAnswer();
vector<ll> mo(vector<query> queries) {
  vector<ll> answers(queries.size());
  int l = 0; int r = -1;
  sort(all(queries));
  each(q, queries) {
    while (q.l < l) add(--l);
    while (r < q.r) add(++r);
    while (l < q.l) remove(l++);
    while (q.r < r) remove(r--);
    answers[q.idx] = getAnswer();
  }
  return answers;
}
vl nums; ll ans = 0; int cnt[1000001];//init nums
void add(int idx) { /*add element at idx and upd ans*/} 
void remove(int idx) { } 
ll getAnswer() { return ans; }
