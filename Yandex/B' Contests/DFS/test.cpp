#include <bits/stdc++.h>

using namespace std;

vector<set<int>> graph;
vector<int> used;

void dfs(int v, int p = -1) {    //p - прямой предок
    used[v] = true;

    for (int u: graph[v]) {
        if (!used[u]) {
            dfs(u, v);
        } else if (u != p) {
            cout << "Graph has cycles.";
            exit(0);    //Полностью выйти из программы.
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a - 1].insert(b - 1);
        graph[b - 1].insert(a - 1);
    }
    used.resize(n);

    //Проверяем отдельно каждую вершину, так как
    //граф может быть несвязным, но всё равно иметь циклы
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }

    //Если мы ещё не вышли не вышли из программы, в графе нет циклов.
    cout << "Graph has no cycles.";
}