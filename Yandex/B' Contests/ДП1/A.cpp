#include <bits/stdc++.h>

using namespace std;

vector<set<int>> graph;
map<int, set<int>> used;

void dfs(int v, int color) {
    used[v].insert(color);
    
}

int main() {
    ios:: sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i ++) {
        int a, b; cin >> a >> b;
        graph[a - 1].insert(b - 1);
        graph[b - 1].insert(a - 1);
    }
    

}