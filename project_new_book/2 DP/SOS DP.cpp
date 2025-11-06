// F(mask) = op(F(x_1), F(x_2), ...) where x is submask of mask
// init sos[z] 
for (int i = 0; i < M; i++) {
  for (int mask = 0; mask < (1 << M); mask++) {
    if (mask & (1 << i)) { 
      sos[mask] += sos[mask ^ (1 << i)]; 
    }		}
}
