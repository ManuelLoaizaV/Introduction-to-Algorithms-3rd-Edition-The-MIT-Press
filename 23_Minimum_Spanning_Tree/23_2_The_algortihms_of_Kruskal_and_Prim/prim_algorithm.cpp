#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
const int INF = 1e9;
int V, key[N], p[N];
bool done[N];
vector<pair<int, int>> adj[N];


void add_edge(int u, int v, int w) {
	adj[u].push_back({v, w});
	adj[v].push_back({u, w});
}

void mst_prim(int root) {
	for (int i = 0; i < V; i++) {
		key[i] = INF;
		p[i] = -1;
	}
	key[root] = 0;
	set<pair<int, int>> Q;
	for (int i = 0; i < V; i++) Q.insert({key[i], i});
	while (not Q.empty()) {
		pair<int, int> w_u = *Q.begin();
		Q.erase(w_u);
		int u = w_u.second;
		done[u] = true;
		for (pair<int, int> e : adj[u]) {
			int v = e.first;
			int w = e.second;
			if (not done[v] and w < key[v]) {
				p[v] = u;
				Q.erase({key[v], v});
				key[v] = w;
				Q.insert({key[v], v});
			}
		}
	}
}

int main() {
	V = 9;
	add_edge(0, 1, 4);
	add_edge(1, 2, 8);
	add_edge(2, 3, 7);
	add_edge(3, 4, 9);
	add_edge(4, 5, 10);
	add_edge(5, 6, 2);
	add_edge(6, 7, 1);
	add_edge(7, 1, 11);
	add_edge(3, 5, 14);
	add_edge(2, 5, 4);
	add_edge(2, 8, 2);
	add_edge(7, 8, 7);
	add_edge(6, 8, 6);
	mst_prim(0);
	int total_weight = 0;
	cout << "Edges in the MST:" << endl;
	for (int u = 0; u < V; u++) {
		int v = p[u];
		int w = key[u];
		if (v == -1) continue;
		cout << "(" << char('a' + u) << ", " << char('a' + v) << "), ";
		cout << "w(" << char('a' + u) << ", " << char('a' + v) << ") = " << w << endl;
		total_weight += w;
	}
	cout << "Total weight : " << total_weight << endl;
	return 0;
}