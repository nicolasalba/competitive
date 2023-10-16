3. Dijkstra

const int inf = 1e9;
vector<pair<int, int>> adj[n];
bool processed[n];
ll distance[n];

void dijkstra() {
	priority_queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		distance[i] = inf;
	}
	distance[start] = 0;
	q.push({0, start});
	while (q.size() > 0) {
		int c = q.top().second;
		q.pop();
		if (processed[c]) continue;
		processed[c] = true;
		for (auto& a : adj[c]) {
			int u = a.first;
			int w = a.second;
			if (distance[c] + w < distance[u]) {
				distance[u] = distance[c] + w;
				q.push({-distance[u], u});
			}
		}
	}
}
