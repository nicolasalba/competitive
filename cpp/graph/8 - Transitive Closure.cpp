8. Transitive Closure

const int inf = 1e9;
vector<int> adj[n];
ll distance[n][n];

void floydWarshall() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			distance[i][j] = false;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int b : adj[i]) {
			distance[i][b] = true;
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				distance[i][j] |= distance[i][k] & distance[k][j];
			}
		}
	}
}