#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<vector<pair<int, ll>>> graph;
vector<int> p, sz;

int getRoot(int v) {
    if (v == p[v]) return v;
    return p[v] = getRoot(p[v]);
}

void unite(int a, int b) {
    a = getRoot(a);
    b = getRoot(b);

    if (a == b) {
        return;
    }

    if (sz[a] > sz[b]) swap(a, b);
    sz[b] += sz[a];
    p[a] = b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++) {
        int b, e; ll w; cin >> b >> e >> w;
        b--; e--;
        graph[b].emplace_back(e, w);
        graph[e].emplace_back(b, w);
    }

    return 0;
}