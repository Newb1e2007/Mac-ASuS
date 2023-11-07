#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<set<pair<int, ll>>> graph;
vector<ll> dp;
vector<int> sz;
vector<ll> answ;
int n;

void dfs1(int v, int p = -1) {
    sz[v] = 1;
    dp[v] = 0;
    for (auto u : graph[v]) {
        if (u.first != p) {
            dfs1(u.first, v);
            sz[v] += sz[u.first];
            dp[v] += dp[u.first] + (ll)sz[u.first] * u.second;
        }
    }
}

void dfs2(int v, int p = -1) {
    for (auto u : graph[v]) {
        if (u.first != p) {
            answ[u.first] = answ[v] + (n - sz[u.first])*u.second - u.second*sz[u.first];
            dfs2(u.first, v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    graph.resize(n);
    dp.resize(n);
    sz.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u; ll w; cin >> v >> u >> w;
        graph[v - 1].insert({u - 1, w});
        graph[u - 1].insert({v - 1, w});
    }
    dfs1(0);
    answ.resize(n);
    answ[0] = dp[0];
    dfs2(0);
    for (int i = 0; i < n; i++) {
        cout << answ[i] << ' ';
    }
    return 0;
}