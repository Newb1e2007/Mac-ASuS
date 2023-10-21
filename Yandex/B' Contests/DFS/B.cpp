#include <bits/stdc++.h>

using namespace std;

void dfs(set<int> &currAnsw, vector<vector<int>> &matrix, vector<int> &visited, int v, int n) {
    if (visited[v - 1] == 1) {return;}
    else {
        currAnsw.insert(v);
        visited[v - 1] = 1;
        for (int j = 0; j < n; j++) {
            if (matrix[v - 1][j] == 1 && visited[j] != 1) {
                dfs(currAnsw, matrix, visited, j + 1, n);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int> (n));
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        matrix[a - 1][b - 1] = 1;
        matrix[b - 1][a - 1] = 1;
    }
    vector<int> visited(n);
    vector<set<int>> answ;
    for (int i = 0; i < n; i++) {
        if (visited[i] != 1) {
            set<int> currAnsw;
            dfs(currAnsw, matrix, visited, i + 1, n);
            answ.push_back(currAnsw);
        }
    }     
    cout << answ.size() << '\n';
    for (auto ks : answ) {
        cout << ks.size() << '\n';
        for (int k : ks) {
            cout << k << ' ';
        }
        cout << '\n';
    }

    return 0;
}