#include <bits/stdc++.h>

using namespace std;
//vector<vector<int>> graph;

struct Edge {
    int a;
    int b;
    int cost;
    bool used = false;
};

vector<Edge> graph;

int dfs(int v, int s) {
    // проверяем можно ли обойти ребро AB за меньшее колво топлива
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int currCost; cin >> currCost;
            Edge e; e.a = i; e.b = j; e.cost = currCost;
            graph.push_back(e);

        }
    }

    int minV = 0;
    for (Edge e : graph) {
        if (!e.used) {
            e.used = true;
            minV = max(minV, dfs(e.a, e.b));
        }
    }
}

