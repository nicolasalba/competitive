9. Kruskal

vector<tuple<int, int, int> edges;


void kruskal() {
	ll res = 0;
	sort(edges.begin(), edges.end());// sorted by weight
	for (auto edge : edges) {
		int a, b, w;
		tie(w, a, b) = edge;
		if (find(a) != find(b)) {
			group(a, b);
			res += w;
		}
	}
}