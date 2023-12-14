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
    vector<bool> used(n);
    for (int i = 0; i < n; i++) {
        int curV = -1;
        ll curDist = INF;
        for (int j = 0; j < n; j++) {
            if (!used[j] && dist[j] < curDist) {
                curV = j;
                curDist = dist[j];
            }
        }
        used[curV] = true;

        for (int j = 0; j < n; j++) {
            dist[j] = min(dist[j], curDist + count_dist(graph[curV], graph[j]));
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