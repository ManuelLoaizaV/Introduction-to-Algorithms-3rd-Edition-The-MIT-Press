#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int V;
vector<pair<int, int>> adj[N];

struct Edge {
	int u, v, w;
	Edge() {}
	Edge(int _u, int _v, int _w) {
		u = _u;
		v = _v;
		w = _w;
	}
	bool operator < (const Edge &o) const { return w < o.w; }
};

int p[N];
void make_set(int u) { p[u] = u; }

int find_set(int u) {
	if (p[u] == u) return u;
	p[u] = find_set(p[u]);
	return p[u];
}

bool same_set(int u, int v) {
	return find_set(u) == find_set(v);
}

void union_sets(int u, int v) {
	int pu = find_set(u);
	int pv = find_set(v);
	if (pu != pv) p[pv] = pu;
}

vector<Edge> mst_kruskal() {
	vector<Edge> A;
	for (int i = 0; i < V; i++) make_set(i);
	vector<Edge> edges;
	for (int u = 0; u < V; u++) {
		for (pair<int, int> e : adj[u]) {
			int v = e.first;
			int w = e.second;
			edges.push_back(Edge(u, v, w));
		}
	}
	sort(edges.begin(), edges.end());
	for (Edge e : edges) {
		if (not same_set(e.u, e.v)) {
			A.push_back(e);
			union_sets(e.u, e.v);
		}
	}
	return A;
}


void add_edge(int u, int v, int w) {
	adj[u].push_back({v, w});
	adj[v].push_back({u, w});
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
	vector<Edge> mst = mst_kruskal();
	int total_weight = 0;
	cout << "Edges in the MST:" << endl;
	for (Edge e : mst) {
		int u = e.u;
		int v = e.v;
		int w = e.w;
		cout << "(" << char('a' + u) << ", " << char('a' + v) << "), ";
		cout << "w(" << char('a' + u) << ", " << char('a' + v) << ") = " << w << endl;
		total_weight += w;
	}
	cout << "Total weight : " << total_weight << endl;
	return 0;
}