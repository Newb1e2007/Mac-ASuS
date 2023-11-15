#include <bits/stdc++.h>

using namespace std;
vector<set<int>> graph;
vector<int> used;
int INF = INT32_MAX;

bool dfs(int v, int s) {
    used[v] = 1;
    if (v == s) return true;
    bool answ = false;
    for (int u : graph[v]) {
        if (!used[u]) {answ += dfs(u, s);} 
        else {
            if (u == s) {
                return true;
            }
        }
    }
    return answ;
}

vector<int> dijkstra(int v, int n) {
    vector<int> dist(n, INF); dist[v] = 0;
    set<pair<int, int>> notVis;
    for (int v = 0; v < n; v++) {
        notVis.insert(make_pair(dist[v], v));
    }
    while (!notVis.empty()) {
        pair<int, int> u = *notVis.begin();
        notVis.erase(u);

        for (int newU : graph[u.second]) {
            if (dist[newU] > dist[u.second] + 1) {
                notVis.erase({dist[newU], newU});
                dist[newU] = dist[u.second] + 1;
                notVis.insert({dist[newU], newU});
            }
        }
    }
    return dist;
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
    vector<int> answ = dijkstra(d - 1, n);
    cout << answ[v - 1];
    return 0;
}