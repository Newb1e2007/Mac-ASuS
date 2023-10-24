#include <bits/stdc++.h>

using namespace std;

vector<set<int>> graph;
vector<int> used;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    graph.resize(n);
    used.resize(n);
    for (int i = 0; i < n; i++) {
        int key; cin >> key;
        graph[key - 1].insert(i); 
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
}