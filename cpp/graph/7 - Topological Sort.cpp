7. Topological Sort

stack<int> topo;
vector<int> adj[n + 1];
bool visited[n + 1];

void dfs(int x) {
	if (visited[x]) return;
	visited[x] = true;
	for (int a : adj[x]) {
		dfs(a);
	}
	topo.push(x);
}