#include <bits/stdc++.h>

using namespace std;

vector<set<int>> graph;
vector<int> used, sz;

void dfs(int v) {
    used[v] = 1;
    for (int u : graph[v]) {
        if (!used[u]) dfs(u);
        sz[v] += sz[u];
    }
}

int main() {
    ios:: sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    graph.resize(n);
    used.resize(n);
    sz.assign(n, 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a - 1].insert(b - 1);
        graph[b - 1].insert(a - 1);
    }
    for (int i = 0; i < )

    int q; cin >> q;
    
}