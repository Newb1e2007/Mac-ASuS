#include <bits/stdc++.h>

using namespace std;

vector<set<int>> graph;
vector<int> used, tin, tout;
int t = 0;

void dfs(int v) {
    tin[v] = t++;
    used[v] = 1;
    for (int u : graph[v]) {
        if (!used[u]) dfs(u);
    }
    tout[v] = t++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    graph.resize(n);
    used.resize(n);
    tin.resize(n);
    tout.resize(n);
    int root;
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        if (p != 0) {
            graph[p - 1].insert(i);
        } else {
            root = i;
        }
    }
    dfs(root);
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        if (tin[a - 1] < tin[b - 1] && tout[a - 1] > tout[b - 1]) 
            cout << 1 << '\n';
        else 
            cout << 0 << '\n';
    }
    return 0;
}