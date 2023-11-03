#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph, graphRev;
vector<int> used, order;

void dfs1() {

}

void dfs2() {
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    graph.resize(n);
    graphRev.resize(n);
    used.resize(n);
    order.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graphRev[b - 1].push_back(a - 1);
    }

}