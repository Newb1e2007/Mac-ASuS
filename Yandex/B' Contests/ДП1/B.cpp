#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> dp;
vector<set<int>> graph;
vector<int> Q;

//dp[v].first - не взяли, dp[v].second - взяли

void dfs(int v) {
    for (auto u : graph[v]) {
        dfs(u);
        dp[v].first += max(dp[u].first, dp[u].second);
        dp[v].second += dp[u].first;
    }
    return;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n; cin >> n;
    graph.resize(n);
    Q.resize(n);
    dp.resize(n);
    int v;
    for (int i = 0; i < n; i++) {
        int pi, qi; cin >> pi >> qi;
        if (pi == 0) {
            v = i;
            Q[i] = qi;
        } else {
            Q[i] = qi;
            graph[pi - 1].insert(i);
        }
    }
    for (int v = 0; v < n; v++) {
        dp[v].second = Q[v];
        dp[v].first = 0;
    }

    dfs(v);
    cout << max(dp[v].first, dp[v].second);
    return 0;
}