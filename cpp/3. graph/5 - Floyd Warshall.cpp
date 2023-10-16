5. Floyd Warshall

const int inf = 1e9;
vector<pair<int, int>> adj[n];
ll distance[n][n];

void floydWarshall() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			distance[i][j] = inf;
		}
	}
	for (int i = 0; i < n; i++) {
		for (auto p : adj[i]) {
			int b = p.first;
			int w = p.second;
			distance[i][b] = w;
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
			}
		}
	}
}