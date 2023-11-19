#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> used, sz, colors;
map<int, int> col_sz;

void dfs(int v, int color, int p = -1) {
    used[v] = 1;
    colors[v] = color;
    col_sz[color]++;
    for (int u : graph[v]) { 
        if (u != p) {
            if (!used[u]) dfs(u, color, v);
            sz[v] += sz[u];
        }
    }
    sz[v] += 1;
}

int main() {
    ios:: sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    graph.resize(n);
    used.resize(n);
    sz.assign(n, 0);
    colors.resize(n);
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
        edges[i] = {a - 1, b - 1};
    }
    int color = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i]) dfs(i, ++color);
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int e; cin >> e;
        int a = edges[e - 1].first, b = edges   [e - 1].second;
        if (sz[a] > sz[b]) swap(a, b);
        int c = col_sz[colors[a]];
        cout << (long long)sz[a] * (long long)(c - sz[a]) << '\n';
    }
    cout.flush();
    return 0;
}