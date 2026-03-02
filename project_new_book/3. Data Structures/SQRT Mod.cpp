/* Sqrt trick for floor(n/i):
floor(n/i) has O(sqrt(n)) distinct values.
Iterate by jumps: for(d=1; d<=n; d=n/(n/d)+1) */

const int MXN = 2e5 + 10; int nums[MXN]; vi ch[MXN];
for (int i =0;i<n;i++) {
  for (int d=1; d<=nums[i]; d=nums[i]/(nums[i]/d)+1) {
    ch[d].pb(i);
  }
  ch[nums[i]+1].pb(i);
}
