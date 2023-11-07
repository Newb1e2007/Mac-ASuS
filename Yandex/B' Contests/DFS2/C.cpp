#include <bits/stdc++.h>

using namespace std;

vector<set<int>> graph, graphRev, newGraph;
vector<int> used, order;

void dfs1(int v) {
    used[v] = 1;
    for (int u : graph[v]) {
        if (!used[u]) dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int color) {
    used[v] = color;
    for (int u : graphRev[v]) {
        if (!used[u]) dfs2(u, color);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    graph.resize(n);
    graphRev.resize(n);
    used.resize(n);
    order.reserve(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a - 1].insert(b - 1);
        graphRev[b - 1].insert(a - 1);
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs1(i);
        }
    }
    reverse(order.begin(), order.end());
    used.assign(n, 0);
    int color = 0;
    for (int u : order) {
        if (!used[u]) {
            dfs2(u, ++color);
        }
    }
    newGraph.resize(color);
    for (int i = 0; i < n; i++) {
        for (int u : graph[i]) {
            if (used[i] != used[u]) {
                newGraph[used[i] - 1].insert(used[u] - 1);
            }
        }
    }
    int answ = 0;
    for (auto i : newGraph) {
        answ += i.size();
    }
    cout << answ;
    return 0;
}