4. BellmanFord

const int inf = 1e9;
vector<tuple<int, int, int>> edges;
ll distance[n];


void bellmanFord() {
	for (int i = 0; i < n; i++) {
		distance[i] = inf;
	}
	distance[start] = 0;
	for (int i = 0; i < n - 1; i++) {
		//bool changed = false; add one iteration (i < n) to valide negative cicles
		for (auto& edge : edges) {
			int a, b, w;
			tie(a, b, w) = edge;
			if (distance[a] + w < distance[b]) {
				distance[b] = distance[a] + w;
				//changed = true;
			}
		}
	}
}