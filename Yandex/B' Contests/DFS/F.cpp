#include <bits/stdc++.h>

using namespace std;

vector<set<int>> graph;
vector<int> used;

int dfs(int v) {
    used[v] = 1;
    int count = 1;
    for (int u : graph[v]) {
        if (!used[u]) {
            count += dfs(u);
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s; cin >> n >> s;
    graph.resize(n);
    used.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int16_t curr; cin >> curr;
            if (curr) {
                graph[i].insert(j);
            }
        }
    }
    int count = 0;
    count = dfs(s - 1);
    cout << count;
    return 0;
}