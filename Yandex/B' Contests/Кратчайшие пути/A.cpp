#include <bits/stdc++.h>

using namespace std;
vector<set<int>> graph;
vector<int> used;

bool dfs(int v, int s) {
    used[v] = 1;
    bool answ = false;
    for (int u : graph[v]) {
        if (!used[u]) answ += dfs(u, s);
        else {
            if (u == s) {
                return true;
            }
        }
    }
    return answ;
}

vector<int> dijkstra(int v) {
    /*vector<int> dist(n, INF); dist[0] = 0;
    set<pair<int, int>> notVis;
    for (int v = 0; v < n; v++) {
        notVis.insert(make_pair(dist[v], v));
    }
    while (!notVis.empty()) {
        pair<int, int> u = *notVis.begin();
        notVis.erase(u);

        for (pair<int, int>& newU : graph[u.second]) {
            if (dist[newU.first] > dist[u.second] + newU.second) {
                notVis.erase({dist[newU.first], newU.first});
                dist[newU.first] = dist[u.second] + newU.second;
                notVis.insert({dist[newU.first], newU.first});
            }
        }
    }
    return dist;*/
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n ; cin >> n;
    graph.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a; cin >> a;
            if (a) {
                graph[i].insert(j);
                graph[j].insert(i);
            }
        }
    }
    used.resize(n);
    int d, v; cin >> d >> v;
    if (!dfs(d - 1, v - 1)) {
        cout << -1;
        return 0;
    }
    vector<int> answ = dijkstra(d);
    cout << answ[v];
    return 0;
}