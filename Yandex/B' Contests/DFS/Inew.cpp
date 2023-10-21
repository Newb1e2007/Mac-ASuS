#include <bits/stdc++.h>

using namespace std;

vector<set<int>> graph;
vector<int> used;
vector<int> usedFF;
vector<int> h;

void dfs(int v) {
    used[v] = 1;
    usedFF[v] = 1;
    for (auto u : graph[v]) {
        if (!used[u]) {
            h[u] = h[v] + 1;
            dfs(u);
        }
    }
    return;
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
    used.resize(n);
    int maxCnt = 1;
    h.resize(n);
    usedFF.resize(n);
    for (int i = 0; i < n; i++) {
        if (!usedFF[i]) {
            vector<int> arr(n);
            for (int i = 0; i < n; i++) {
                arr[i] = i;
                h[i] = 1;
                used[i] = 0;
            }
            dfs(i);
            sort(arr.begin(), arr.end(), [ & ](int i, int j) {return h[i] > h[j];});
            int v = arr[0];
            for (int i = 0; i < n; i++) {
                arr[i] = i;
                h[i] = 1;
                used[i] = 0;
            }
            dfs(v);
            sort(arr.begin(), arr.end(), [ & ](int i, int j) {return h[i] > h[j];});
            int u = arr[0];
            maxCnt = max(maxCnt, h[u]);
        }
    }
    cout << maxCnt;
}