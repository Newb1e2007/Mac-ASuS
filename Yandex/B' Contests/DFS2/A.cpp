#include <bits/stdc++.h>

using namespace std;

vector<set<int>> graph, graphRev;
vector<int> used, newUsed, order, newOrder;

void dfs1(int v) {
    used[v] = 1;
    for (auto u : graphRev[v]) {
        if (!used[u]) {
            dfs1(u);
        }
    }
    order.push_back(v);
}

void dfs2(int v, int color) {
    used[v] = color;
    for (auto u : graph[v]) {
        if (!used[u]) {
            dfs2(u, color);
        }
    }
}

void dfs3(int v) {
    newUsed[v] = 1;
    for (auto u : graph[v]) {
        if (!newUsed[u]) {
            dfs3(u);
        }
    }
    newOrder.push_back(used[v]);
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
    int color = 1;
    used.assign(n, 0);
    for (int v : order) {
        if (!used[v]) {
            dfs2(v, color);
            color++;
        }
    }
    cout << color - 1 << '\n';
    /*for (int i = 0; i < n; i++) {
        for (auto u : graph[i]) {
            if (used[u] != used[i]) {
                newGraph[i].insert(u);
            }
        }
    }*/
    newUsed.resize(n);
    //used.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (!newUsed[i]) {
            dfs3(i);
        }
    }
    reverse(newOrder.begin(), newOrder.end());
    for (auto el : newOrder) {
        cout << el << ' ';
    }
    return 0;
}