#include <bits/stdc++.h>

using namespace std;

vector<set<int>> graph;
vector<int> used;
int cyclCnt = 0;

void dfs(int v, int p) {
    used[v] = p;
    for (int u : graph[v]) {
        if (used[u] == -1) dfs(u, p);
        else if (used[u] == p) cyclCnt++;
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    graph.resize(n);
    used.resize(n, -1);
    for (int i = 0; i < n; i++) {
        int key; cin >> key;
        graph[key - 1].insert(i); 
    }
    for (int i = 0; i < n; i++) {
        if (used[i] == -1) {
            dfs(i, i);
        }
    }
    cout << cyclCnt;
    return 0;
}