2. BFS

vector<int> adj[n + 1];
bool visited[n + 1];

void bfs() {
	queue<int> q;
	q.push(0); // initial node
	visited[0] = true;
	while(q.size() > 0) {
		int c = q.front();
		q.pop();
		for (int a : adj[c]) {
			if (visited[a]) continue;
			q.push(a);
			visited[a] = true;
		}
	}	
}