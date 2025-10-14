No se si tiene un nombre, pero en varios problemas vi este truco:

dp[x] = f(x,y) donde se necesita un optimo 'y'.

Truco: si puedes separarlo en f(x,y) en f(x) (+) f(y), puedes guardar en una estructa optima f(y) como un segment tree.
