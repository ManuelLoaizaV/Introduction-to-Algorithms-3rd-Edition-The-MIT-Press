#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int V;
vector<int> g[N], gt[N];
vector<int> order, cur;
vector<vector<int>> comp;
bool used[N];

void DFS1(int u) {
	used[u] = true;
	for (int v : g[u]) if (not used[v]) DFS1(v);
	order.push_back(u);
}

void DFS2(int u) {
	used[u] = true;
	cur.push_back(u);
	for (int v : gt[u]) if (not used[v]) DFS2(v);
}

int main() {
	V = 8;
	// G es un grafo dirigido
	g[0].push_back(1);
	g[1].push_back(2);
	g[1].push_back(5);
	g[1].push_back(4);
	g[2].push_back(3);
	g[2].push_back(6);
	g[3].push_back(2);
	g[3].push_back(7);
	g[4].push_back(0);
	g[4].push_back(5);
	g[5].push_back(6);
	g[6].push_back(5);
	g[6].push_back(7);
	g[7].push_back(7);
	// GT es la transpuesta de G
	gt[1].push_back(0);
	gt[2].push_back(1);
	gt[5].push_back(1);
	gt[4].push_back(1);
	gt[3].push_back(2);
	gt[6].push_back(2);
	gt[2].push_back(3);
	gt[7].push_back(3);
	gt[0].push_back(4);
	gt[5].push_back(4);
	gt[6].push_back(5);
	gt[5].push_back(6);
	gt[7].push_back(6);
	gt[7].push_back(7);
	for (int u = 0; u < V; u++) if (not used[u]) DFS1(u);
	for (int i = 0; i < V; i++) used[i] = false;
	for (int i = 0; i < V; i++) {
		int u = order[V - 1 - i];
		if (not used[u]) {
			DFS2(u);
			comp.push_back(cur);
			cur.clear();
		}
	}
	int sz = comp.size();
	for (int i = 0; i < sz; i++) {
		cout << "Componente " << i + 1 << " : ";
		for (int u : comp[i]) cout << char('a' + u) << " ";
		cout << endl;
	}
	return 0;
}