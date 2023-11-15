#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> nGraphRev;
vector<vector<pair<int, int>>> graph;
vector<pair<pair<int, int>, int>> nGraph;
vector<int> used;

void dfs(int v) {
    for (auto u : graph[v]) {
        if (!used[u.second]) {
            used[u.second] = 1;
            nGraphRev[u.first].push_back(v);
            nGraph.push_back(make_pair(make_pair(v, u.first), u.second));
            dfs(u.first);
        }
    }
}

void dfs2(int v) {
    used[v] = 1;
    for (int u : nGraphRev[v]) {
        if (!used[u]) dfs2(u);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin  >> n >> m;
    graph.resize(n);
    used.resize(m);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a - 1].push_back(make_pair(b - 1, i));
        graph[b - 1].push_back(make_pair(a - 1, i));
    }
    for (auto v : graph) {
        if (v.size() < 2) {
            cout << 0;
            return 0;
        }
    }
    nGraph.reserve(n);
    nGraphRev.resize(n);
    dfs(0);
    used.resize(n, 0);
    dfs2(0);
    for (int i : used) {
        if (!i) {
            cout << 0;
            return 0;
        }
    }
    sort(nGraph.begin(), nGraph.end(), [ & ](pair<pair<int, int>, int> i, pair<pair<int, int>, int> j) {
        return i.second < j.second;
    });
    for (auto el : nGraph) {
        cout << el.first.first + 1 << ' ' << el.first.second + 1 << '\n';
    }
    return 0;
}