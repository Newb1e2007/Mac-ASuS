#include <bits/stdc++.h>

using namespace std;

vector<set<int>> graph;
vector<int> used;

/*int dfs(int v, int p = -1) {
    int currCnt = 1;
    for (auto u : graph[v]) {
        if (v > p && u == v + 1) {
            currCnt += dfs(u, v);
        } else if (v < p && u == v - 1){
            currCnt += dfs(u, v);
        }
    }
    return currCnt;
}*/

int dfs(int v) {
    int currCnt = 1;
    used[v] = 1;
    for (auto u : graph[v]) {
        if (!used[u]) {
            currCnt = max(currCnt, 1 + dfs(u));
        }
    }
    cout << currCnt << ' ' << v << '\n';
    return currCnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    graph.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        graph[a - 1].insert(b - 1);
        graph[b - 1].insert(a - 1);
    }
    int maxCnt = 1;
    for (int i = 0; i < n; i++) {
        used.resize(n);
        int cnt = dfs(i);
        maxCnt = max(maxCnt, cnt);
    }
    cout << maxCnt;
}