x&(x-1)   // Turn off rightmost 1bit
x&-x      // Isolate rightmost 1bit
x|(x-1)   // Right propagate rightmost 1bit
x|(x+1)   // Turn on rightmost 0bit
~x&(x+1)  // Isolate rightmost 0bit

__builtin_popcount(x)  // count set bits
__builtin_parity(x)    // parity of set bits
__builtin_clz(x)       // leading zeros
__builtin_ctz(x)       // trailing zeros
__builtin_ffs(x)       // 1+index lowest 1

for(int s=m;s;s=(s-1)&m)   // submasks ↓
for(int s=0;s=(s-m)&m;)    // submasks ↑