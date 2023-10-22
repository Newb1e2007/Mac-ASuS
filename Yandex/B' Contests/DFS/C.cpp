#include <bits/stdc++.h>

using namespace std;

vector<set<int>> graph;
vector<int> used;
vector<int> comps;

void dfs(int v, int color) {
    used[v] = 1;
    comps[v] = color;
    for (auto u : graph[v]) {
        if (!used[u]) {
            dfs(u, color);
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, t; cin >> n >> m >> t;
    graph.resize(n);
    used.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        if (a != t && b != t) {
            graph[a - 1].insert(b - 1);
            graph[b - 1].insert(a - 1);
        }
    }
    comps.resize(n);
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i, i);
        }
    }

    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        int u, v; cin >> u >> v;
        if (comps[u - 1] == comps[v - 1]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}