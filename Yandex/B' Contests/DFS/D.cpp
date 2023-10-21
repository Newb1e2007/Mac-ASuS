#include <bits/stdc++.h>

using namespace std;

vector<set<int>> graph;
vector<int> color;

bool dfs(int v) {
    for (int u : graph[v]) {
        if (!color[u]) {
            color[u] = 3 - color[v];
            if (!dfs(u)) {
                return false;
            }
        } else if (color[u] == color[v]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    graph.resize(n);
    color.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a - 1].insert(b - 1);
        graph[b - 1].insert(a - 1);
    }
    for (int i = 0; i < n; i++) {
        if (!color[i]) {
            color[i] = 1;
            if(!dfs(i)) {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}