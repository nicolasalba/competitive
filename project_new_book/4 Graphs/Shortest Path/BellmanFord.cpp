/* BellmanFord O(|Nodes| * |Edges|) 
Finds shortest path in a directed or undirected graph with negative weights.
Also you can find if the graph has negative cycles.
*/
const int inf = 1e9; // Check max possible distance value!!!
vector<tuple<int, int, int>> edges;
ll distance[n];

void bellmanFord() {
	for (int i = 0; i < n; i++) {
		distance[i] = inf;
	}
	distance[start] = 0;
	for (int i = 0; i < n - 1; i++) {
		//bool changed = false; 
		// add one iteration (i < n) to valide negative cicles
		for (auto& edge : edges) {
			int a, b, w;
			tie(a, b, w) = edge;
			if (distance[a] + w < distance[b]) {
				distance[b] = distance[a] + w;
				//changed = true; 
			}
		}
		// if changed after all iterations, then exists negative cycle
	}
}