#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
vector<set<int>> graph, graphRev, newGraph;
vector<int> used, order;

void dfs1(int v) { 
    used[v] = 1;
    for (int u : graph[v]) {
        if (!used[u]) dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int color) {
    used[v] = color;
    for (auto u : graphRev[v]) {
        if (!used[u]) dfs2(u, color);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    graph.resize(n * m);
    graphRev.resize(n * m);
    order.resize(n * m);
    vector<vector<pii>> arr(n, vector<pii> (m));
    used.resize(n * m);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j].first;
            arr[i][j].second = cnt++;
        }
    }
    /*
    for (int  i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j].first << ' ' << arr[i][j].second << "; ";
        }
        cout << '\n';
    }
    return 0;*/
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0 && arr[i - 1][j].first >= arr[i][j].first) {
                graphRev[arr[i][j].second].insert(arr[i - 1][j].second);
                graph[arr[i - 1][j].second].insert(arr[i][j].second);
            } 
            /*else if (i > 0 && arr[i - 1][j] == arr[i][j]) {
                graphRev[arr[i - 1][j].second].insert(arr[i][j].second);
                graphRev[arr[i][j].second].insert(arr[i - 1][j].second);
                graph[arr[i - 1][j].second].insert(arr[i][j].second);
                graph[arr[i][j].second].insert(arr[i - 1][j].second);
            } else */
            if (i > 0 && arr[i - 1][j].first <= arr[i][j].first) {
                graph[arr[i][j].second].insert(arr[i - 1][j].second);
                graphRev[arr[i - 1][j].second].insert(arr[i][j].second);
            }
            if (j > 0 && arr[i][j - 1].first >= arr[i][j].first) {
                graphRev[arr[i][j].second].insert(arr[i][j - 1].second);
                graph[arr[i][j - 1].second].insert(arr[i][j].second);
            } 
            /*else if (j > 0 && arr[i][j - 1] == arr[i][j]) {
                graph[arr[i][j - 1].second].insert(arr[i][j].second);
                graphRev[arr[i][j].second].insert(arr[i][j - 1].second);
                graph[arr[i][j].second].insert(arr[i][j - 1].second);
                graphRev[arr[i][j - 1].second].insert(arr[i][j].second);
            } else*/  
            if (j > 0 && arr[i][j - 1].first <= arr[i][j].first) {
                graphRev[arr[i][j - 1].second].insert(arr[i][j].second);
                graph[arr[i][j].second].insert(arr[i][j - 1].second);
            }
            if (i < n - 1 && arr[i + 1][j].first >= arr[i][j].first) {
                graphRev[arr[i][j].second].insert(arr[i + 1][j].second);
                graph[arr[i + 1][j].second].insert(arr[i][j].second);
            }
            /*if (i < n - 1 && arr[i + 1][j] == arr[i][j]) {
                graphRev[arr[i][j].second].insert(arr[i + 1][j].second);
                graph[arr[i + 1][j].second].insert(arr[i][j].second);
                graphRev[arr[i + 1][j].second].insert(arr[i][j].second);
                graph[arr[i][j].second].insert(arr[i + 1][j].second);
            }*/
            if (i < n - 1 && arr[i + 1][j].first <= arr[i][j].first) {
                graphRev[arr[i + 1][j].second].insert(arr[i][j].second);
                graph[arr[i][j].second].insert(arr[i + 1][j].second);
            }
            if (j < n - 1 && arr[i][j + 1].first >= arr[i][j].first) {
                graphRev[arr[i][j].second].insert(arr[i][j + 1].second);
                graph[arr[i][j + 1].second].insert(arr[i][j].second);
            } 
            /*else if (j < n - 1 && arr[i][j + 1] == arr[i][j]) {
                graphRev[arr[i][j].second].insert(arr[i][j + 1].second);
                graph[arr[i][j + 1].second].insert(arr[i][j].second);
                graphRev[arr[i][j + 1].second].insert(arr[i][j].second);
                graph[arr[i][j].second].insert(arr[i][j + 1].second);
            } else */
            if (j < n - 1 && arr[i][j + 1].first <= arr[i][j].first) {
                graphRev[arr[i][j + 1].second].insert(arr[i][j].second);
                graph[arr[i][j].second].insert(arr[i][j + 1].second);
            }
        }
    }
    for (int i = 0; i < n*m; i++) {
        cout << i << ": ";
        for (int j : graph[i]) {
            cout << j << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for (int i = 0; i < n * m; i++) {
        if (!used[i]) dfs1(i);
    }
    used.assign(n * m, 0);
    int color = 0;
    reverse(order.begin(), order.end());
    for (auto v : order) {
        if (!used[v]) {
            color++;
            dfs2(v, color);
        }
    }  
    newGraph.resize(color);
    for (int v = 0; v < n; v++) {
        for (auto u : graph[v]) {
            if (used[v] != used[u]) {
                newGraph[used[v] - 1].insert(used[u] - 1);
            }
        }
    }
    for (int i = 0; i < color; i++) {
        cout << i << ": ";
        for (auto v : newGraph[i]) cout << v << ' ';
        cout << '\n';
    }
    cout << '\n';
    int answ = 0;
    for (auto v : newGraph) {
        if (v.empty()) answ++;
    }
    cout << answ;   
    return 0;
}