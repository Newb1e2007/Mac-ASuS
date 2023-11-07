#include <bits/stdc++.h> 

using namespace std;

vector<set<int>> graph, graphRev;
vector<int> used, order, allP, canTouch;
unordered_set<int> answ;
int n;

void dfs(int v) {
    used[v] = 1;
    for (int u : graphRev[v]) {
        if (!used[u]) dfs(u);
    }
    order.push_back(v);
}

void dfs2(int v, int p = -1) {
    used[v] = 1;
    int cnt = 0;
    for (auto u : graphRev[v]) {
        if (canTouch[u]) {cnt++;}
    }
    if (cnt > 1) {
        graphRev[v].erase(p);
        return;
    } else {
        answ.insert(v);
        for (int u : graph[v]) {
            if (!used[u] && canTouch[u]) dfs2(u, v);
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    graph.resize(n);
    graphRev.resize(n);
    used.resize(n);
    allP.resize(n);
    order.reserve(n); 
    for (int i = 0; i < n; i++) {
        cin >> allP[i];
    } 
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int a; cin >> a;
            graph[a - 1].insert(i);
            graphRev[i].insert(a - 1);
        }
    }
    //for (int i = 0; i < n; i++) {
    //   if (!used[i]) dfs(i);
    //}
    dfs(0);
    canTouch.resize(n);
    for (int i = 0; i < n; i++) {
        if (used[i]) canTouch[i] = 1;
    }
    //reverse(order.begin(), order.end());
    vector<int> dp(n);
    for (int v : order) {
        for (int u : graphRev[v]) {
            dp[v] = max(dp[u], dp[v]);
        }
        dp[v] += allP[v];
    }
    cout << dp[0] << ' ';
    //graphRev
    used.assign(n, 0);

    for (int v : order) {
        dfs2(v);
    }
    vector<int> answV(answ.size());
    int ind = answ.size() - 1;
    for (auto i : answ) answV[ind--] = i + 1;
    cout << answ.size() << '\n';
    for (int i : answV) cout << i << ' ';
    return 0;
}