#include <bits/stdc++.h>

using namespace std;
vector<vector<pair<int, int>>> graph;
vector<int> p;
int n;

vector<int> dijkstra(int s, int f) {
    vector<int> dist(n, 2e9); dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> notVis;
    for (int v = 0; v < n; v++) {
        notVis.emplace(dist[v], v);
    }
    while (!notVis.empty()) {
        auto [d, v] = notVis.top();
        notVis.pop();
        if (v == f) {
            break;
        }
        for (const auto& [u, d1] : graph[v]) {
            if (dist[u] > d1 + dist[v]) {
                dist[u] = d1 + dist[v];
                p[u] = v;
                notVis.emplace(dist[u], u);
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("dist.in", "r", stdin);
    freopen("dist.out", "w", stdout);

    int m; cin >> n >> m;
    p.resize(n, -1);
    int s, t; cin >> s >> t;
    graph.resize(n);
    for (int i = 0; i < m; i++) {
        int b, e, w; cin >> b >> e >> w;
        graph[b - 1].emplace_back(e - 1, w);
        graph[e - 1].emplace_back(b - 1, w);
    }
    vector<int> answ = dijkstra(s - 1, t - 1);
    if (answ[t - 1] == 2e9) {
        cout << -1 << '\n';
        return 0;
    } else {
        cout << answ[t - 1] << '\n';
        vector<int> path;
        for (int v = t - 1; v != -1; v = p[v]) {
            path.push_back(v);
        }
        //path.push_back(s - 1);
        reverse(path.begin(), path.end());
        cout << path.size() << '\n';
        for (auto el : path) {
            cout << el + 1 << ' ';
        }
    }
    return 0;
}