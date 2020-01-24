#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 1e5;

int V, t;
vector<int> adj[N];
int color[N], p[N], d[N], f[N];

void DFS_visit(int u) {
	t++;
	d[u] = t;
	color[u] = 1;
	for (int v : adj[u]) {
		if (color[v] == 0) {
			p[v] = u;
			DFS_visit(v);
		}
	}
	color[u] = 2;
	t++;
	f[u] = t;
}

void DFS() {
	for (int u = 0; u < V; u++) {
		color[u] = 0;
		p[u] = -1;
	}
	t = 0;
	for (int u = 0; u < V; u++)
		if (color[u] == 0)
			DFS_visit(u);
}

int main() {
	V = 6;
	adj[0].push_back(1);
	adj[0].push_back(3);
	adj[1].push_back(4);
	adj[2].push_back(4);
	adj[2].push_back(5);
	adj[3].push_back(1);
	adj[4].push_back(3);
	adj[5].push_back(5);
	DFS();
	return 0;
}