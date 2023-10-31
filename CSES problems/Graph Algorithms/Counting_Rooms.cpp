#include <bits/stdc++.h>

using namespace std;

vector<set<int>> graph;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    int cnt = 0;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char x; cin >> x;
            if (x == '.') {
                cnt++;
                arr[i][j] = cnt;
            } else {
                arr[i][j] = 0;
            }
        }
    }
    graph.resize(cnt);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j]) {
                
            }
        }
    }
}