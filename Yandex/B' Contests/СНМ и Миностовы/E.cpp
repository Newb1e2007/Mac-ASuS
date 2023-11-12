#include <bits/stdc++.h>

using namespace std;
vector<int> p, sz;
double eps = 1e-4;

struct Edge {
    int u, v;
    double w;
};

int dist(int x1, int y1, int x2, int y2) {
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
        return abs(i.w - j.w) > eps;
    });
    for (auto edge : edges) {
        cout << edge.u << ' ' << edge.v << ' ' << edge.w << '\n';
    }
    double answ = 0;
    for (auto edge : edges) {
        if (getRoot(edge.u) != getRoot(edge.v)) {
            answ += edge.w;
            unite(edge.u, edge.v);
        }
    }
    cout << fixed << setprecision(10) << answ;
    return 0;
}