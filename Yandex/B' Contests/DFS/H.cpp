#include <bits/stdc++.h>

using namespace std;

vector<set<int>> graph;
vector<int> used;

bool dfs(int v) {
    used[v] = 1;
    for (int u : graph[v]) {
        if (!used[u]) {
            if (dfs(u)) {
                return true;
            }
        } else {
            return true;
        }
    }
    used[v] = 0;
    for (int u : graph[v]) {
        used[u] = 0;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a - 1].insert(b - 1);
    }
    used.resize(n);
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            if (dfs(i)) {
                cout << 1;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}