#include <bits/stdc++.h>

using namespace std;

vector<set<int>> graph, graphRev, newGraph;
vector<int> used, order;

void dfs1(int v) {
    used[v] = 1;
    for (auto u : graph[v]) {
        if (!used[u]) dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int color) {
    used[v] = color;
    for (auto u : graphRev[v]) {
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
    used.assign(n, 0);
    int color = 0;
    reverse(order.begin(), order.end());
    for (auto v : order) {
        if (!used[v]) {
            color++;
            dfs2(v, color);
        }
    }
    newGraph.resize(color);
    for (int v = 0; v < n; v++) {
        for (auto u : graph[v]) {
            if (used[v] != used[u]) {
                newGraph[used[v] - 1].insert(used[u] - 1);
            }
        }
    }

    /*for (auto i : used) {
        cout << i << ' ';
    }
    return 0;
    for (int i = 0; i < color; i++) {
        for (auto u : graph[i]) {
            cout << i << ' ' << u << '\n';
        }
    }
    return 0;*/

    int answ = 0;
    for (auto v : newGraph) {
        if (v.empty()) answ++;
    }
    cout << answ;   
    return 0;
}