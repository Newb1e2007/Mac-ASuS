#include <bits/stdc++.h>

using namespace std;
vector<int> p, sz;
double eps = 1e-4;

struct Edge {
    int u, v;
    double w;
};

int dist(int x1, int y1, int x2, int y2) {
    if (x1 < 0 && x2 < 0) {
        x2 += abs(x1);
        x1 = 0;
    }
    if (y1 < 0 && y2 < 0) {
        y2 += abs(y1);
        y1 = 0;
    }
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int getRoot(int v) {
    if (p[v] == v) return v;
    return p[v] = getRoot(p[v]);
}

void unite(int a, int b) {
    a = getRoot(a);
    b = getRoot(b);
    if (a == b) return;
    if (sz[a] > sz[b]) swap(a, b);
    p[a] = b;
    sz[b] += sz[a];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    p.resize(n);
    sz.resize(n, 1);
    iota(p.begin(), p.end(), 0);
    vector<pair<int, int>> vertexes(n);
    for (int i = 0; i < n; i++) {
        cin >> vertexes[i].first >> vertexes[i].second;
    }
    vector<Edge> edges;
    edges.reserve(n*(n - 1)/2);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            Edge e; e.u = i; e.v = j; e.w = sqrt((double)dist(vertexes[i].first, vertexes[i].second, vertexes[j].first, vertexes[j].second));
            edges.push_back(e);
        }
    }
    sort(edges.begin(), edges.end(), [ & ](Edge i, Edge j){
        //return i.w < j.w;
        return j.w - i.w > -eps;
    });
    /*for (auto edge : edges) {
        cout << edge.u << ' ' << edge.v << ' ' << edge.w << "; ";
    }
    cout << '\n' << '\n';*/
    double answ = 0;
    for (auto edge : edges) {
        if (getRoot(edge.u) != getRoot(edge.v)) {
            //cout << edge.u << ' ' << edge.v << ' ' << edge.w << '\n';
            answ += edge.w;
            unite(edge.u, edge.v);
        }
    }
    cout << fixed << setprecision(10) << answ   ;
    return 0;       
}

/*int n;
vector < vector<int> > g;
const int INF = 1000000000; // значение "бесконечность"
 
// алгоритм
vector<bool> used (n);
vector<int> min_e (n, INF), sel_e (n, -1);
min_e[0] = 0;
for (int i=0; i<n; ++i) {
	int v = -1;
	for (int j=0; j<n; ++j)
		if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
			v = j;
	if (min_e[v] == INF) {
		cout << "No MST!";
		exit(0);
	}
 
	used[v] = true;
	if (sel_e[v] != -1)
		cout << v << " " << sel_e[v] << endl;
 
	for (int to=0; to<n; ++to)
		if (g[v][to] < min_e[to]) {
			min_e[to] = g[v][to];
			sel_e[to] = v;
		}
}*/

/*Explain
const int maxn = 1e5, inf = 1e9;
bool used[maxn];
vector< pair<int, int> > g[maxn];
int min_edge[maxn] = {inf}, best_edge[maxn];
min_edge[0] = 0;

// ...

for (int i = 0; i < n; i++) {
    int v = -1;
    for (int u = 0; u < n; u++)
        if (!used[u] && (v == -1 || min_edge[u] < min_edge[v]))
            v = u;

    used[v] = 1;
    if (v != 0)
        cout << v << " " << best_edge[v] << endl;

    for (auto e : g[v]) {
        int u = e.first, w = e.second;
        if (w < min_edge[u]) {
            min_edge[u] = w;
            best_edge[u] = v;
        }
    }
}*/