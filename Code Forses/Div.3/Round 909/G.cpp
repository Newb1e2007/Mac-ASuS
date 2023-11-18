#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<int>& used, vector<int>& parents, int v) {
    used[v] = 1;
    for (int u : graph[v]) {
        if (!used[u])  {
            parents[u] = v;
            dfs(graph, used, parents, u);
        }
    }
}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> parents(n);
    parents[0] = 0;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    vector<int> P(n);
    for (int i = 0; i < n; i++) {
        cin >> P[i];
    }
    vector<int> L(q), X(q), R(q);
    for (int i = 0; i < q; i++) {
        cin >> L[i] >> X[i] >> R[i];
    }
    vector<int> used(n);
    dfs(graph, used, parents, 0);
    for (int i = 0; i < q; i++) {
        int x = X[i] - 1;
        bool flag = true;
        for (int j = L[i] - 1; j <= R[i] - 1; j++) {
            if (!flag) {
                break;
            }
            for (int v : graph[x]) {
                if (v != parents[x] && v == P[j] - 1) {
                    cout << "YES\n";
                    flag = false;
                    break;
                }
            }
        }
        if (flag) cout << "NO\n";
    } 
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}