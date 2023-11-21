#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using coords = pair<int, int>;
using plln = pair<ll, int>;
int n;
ll INF = 1e13;
vector<coords> graph;

ll count_dist(coords v, coords u) {
    return (ll)(v.first - u.first)*(ll)(v.first - u.first) + (ll)(v.second - u.second)*(ll)(v.second - u.second);
}

ll dijkstra(int v, int t) {
    vector<ll> dist(n, INF); dist[v] = 0;
    vector<int> used(n);
    priority_queue<plln, vector<plln>, greater<plln>> notVis;
    for (int i = 0; i < n; i++) {
        notVis.emplace(dist[i], i);
    }
    while (!notVis.empty()) {
        auto [d, curV] = notVis.top();
        notVis.pop();
        used[curV] = 1;
        if (graph[curV].first == graph[t].first && graph[v].second == graph[t].second) {
            break;
        }
        for (int i = 0; i < n; i++) {
            if (!used[i] && dist[i] > d + count_dist(graph[curV], graph[i])) {
                dist[i] = d + count_dist(graph[curV], graph[i]);
                notVis.emplace(dist[i], i);
            }
        }
    }
    return dist[t];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    graph.resize(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        graph[i].first = x; graph[i].second = y;
    }
    int s, t; cin >> s >> t; s--; t--;
    cout << dijkstra(s, t);
    return 0;
}