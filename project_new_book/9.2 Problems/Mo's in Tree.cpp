DFS Euler 2N:  array A con cada nodo 2 veces 
               (ST[u] entrada, EN[u] salida).

En Mo, add(pos) togglea el nodo A[pos] 
(activo <-> inactivo).

Query (u,v), p=LCA(u,v), con ST[u]≤ST[v]:

si p==u: rango [ST[u], ST[v]]
si p!=u: rango [EN[u], ST[v]] 
   y agregás p aparte (toggle antes/después).
