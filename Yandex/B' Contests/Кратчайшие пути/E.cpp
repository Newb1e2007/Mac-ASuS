#include <bits/stdc++.h>

struct coords{
    int x, y;  
};

using namespace std;
using pii = pair<int, int>;

vector<vector<pii>> graph;
vector<int> p;
map<int, coords>;
int INF = INT32_MAX;
int n;

vector<int> dijkstra(int s, int f) {
    vector<int> dist(n, INF); dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> notVis;
    for (int i = 0; i < n; i++) {
        notVis.emplace(dist[i], i);
    }
    while (!notVis.empty()) {
        auto [d, v] = notVis.top();
        notVis.pop();
        if (v == f) break;
        for (const auto& [u, d2] : graph[v]) {
            if (dist[u] > dist[v] + d2) {
                dist[u] = dist[v] + d2;
                notVis.emplace(dist[u], u);
                p[u] = v;
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    for (int v = 0; v < )
}