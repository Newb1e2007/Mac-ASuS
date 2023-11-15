#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
vector<set<pii>> graph;
int n;
int INF = 1e9;

int dijkstra(int s, int f) {
    vector<int> dist(n, INF); dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> notVis;
    for (int i = 0; i < n; i++) {
        notVis.emplace(dist[i], i);
    }
    while (!notVis.empty()) {
        auto [d, v] = notVis.top();
        notVis.pop();
        if (v == f) {
            break;
        }
        for (const auto& [u, w] : graph[v]) {
            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                notVis.emplace(dist[u], u);
            }
        }
    }
    return dist[f];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int m; cin >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a - 1].emplace(b - 1, arr[a - 1]);
        graph[b - 1].emplace(a - 1, arr[b - 1]);
    }
    int answ = dijkstra(0, n - 1);
    if (answ == INF) {
        cout << -1;
    } else {
        cout << answ;
    }
    return 0;
}