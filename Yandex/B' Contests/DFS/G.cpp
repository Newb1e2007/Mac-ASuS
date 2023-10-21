#include <bits/stdc++.h>

using namespace std;

vector<set<int>> graph;
vector<int> used;

/*bool dfs1(int len, int v) {
    used[v] = 1;
    len++;
    for (int u : graph[v]) {
        if (!used[u]) {
            if (dfs1(len, u)) {
                return true;
            }
        } else {
            if (len >= 2) {
                return true; 
            } else {
                len--;
                return false;
            }
        }
    }
    len--;
    return false;
}*/
void dfs(int v, int p = -1) {
    used[v] = true;

    for (int u: graph[v]) {
        if (!used[u]) {
            dfs(u, v);
        } else if (u != p) {
            cout << "No";
            exit(0);
        }
    }
}

/*void dfs2(int v) {
    used[v] = 1;
    for (int u : graph[v]) {
        if (!used[u]) {
            dfs2(u);
        }
    }
    return;
}*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a - 1].insert(b - 1);
        graph[b - 1].insert(a - 1);
    }
    if (n != m + 1) {
        cout << "No";
        return 0;
    }
    used.resize(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
            cnt++;
        }
    }
    if (cnt > 1) {
        cout << "No";
    } else  {
        cout << "Yes";
    }
    return 0;
}