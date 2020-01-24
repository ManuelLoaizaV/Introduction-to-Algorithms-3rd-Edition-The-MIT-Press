#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 1e5;

int V, t;
vector<int> adj[N];
int color[N], p[N], d[N], f[N];
string clothes[] = {"shirt", "tie", "jacket", "belt", "watch", "undershorts", "pants", "socks", "shoes"};
deque<int> sorted_dag;

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
	sorted_dag.push_front(u);
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

void topological_sort() {
	DFS();
}

int main() {
	V = 9;
	adj[0].push_back(1);
	adj[1].push_back(2);
	adj[0].push_back(3);
	adj[3].push_back(2);
	adj[5].push_back(6);
	adj[6].push_back(3);
	adj[5].push_back(8);
	adj[6].push_back(8);
	adj[7].push_back(8);
	topological_sort();
	cout << "Order for getting dressed:" << endl;
	for (int i = 0; i < V; i++) cout << clothes[sorted_dag[i]] << " ";
	cout << endl;
	return 0;
}