#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using coords = pair<int, int>;
using pllc = pair<ll, coords>;
int n;
int INF = 1e13;
vector<coords> graph;

ll count_dist(coords v, coords u) {
    return (ll)(v.first - u.first)*(ll)(v.first - u.first) + (ll)(v.second - u.second)*(ll)(v.second - u.second);
}

int dijkstra(int v, int t) {
    vector<vector<ll>> dist(n, vector<ll>(n)); dist[graph[v].first][graph[v].second] = 0;
    priority_queue<pllc, vector<pllc>, greater<pllc>> notVis;
    for (int i = 0; i < n; i++) {
        notVis.emplace(dist[graph[i].first][graph[i].second], graph[i]);
    }
    while (!notVis.empty()) {
        auto [d, crds] = notVis.top();
        if (crds.first == graph[t].first && crds.second == graph[t].second) {
            break;
        }
        for (int i = )
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

}