/* Dijkstra O(M + N * log M)
Finds the shortest path in a directed or undirected 
graph with non-negative weights. */

const int inf = 1e9; // check max possible dist!!!!
vector<pair<int, int>> adj[n];
bool processed[n];
ll distance[n]; // Distance from Start to 'i'

void dijkstra() {
	priority_queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		distance[i] = inf;
	}
	int start = 0;
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
