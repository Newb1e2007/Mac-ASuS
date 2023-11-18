#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll INF = 3e10;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<ll>> dp(n, vector<ll>(n, INF));
    vector<vector<int>> from(n, vector<int> (n, -1));
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        ll w; cin >> w;
        from[a - 1][b - 1] = a - 1;
        dp[a - 1][b - 1] = min(dp[a - 1][b - 1], w);
    }
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][k] != INF && dp[k][j] != INF && dp[i][j] > dp[k][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    dp[i][j] = max(dp[i][j], -INF);
                    from[i][j] = from[k][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (dp[i][i] < 0) {
            cout << "LOOP\n";
            vector<int> path;
            path.push_back(i);
            for (int j = from[i][i]; j != i; j = from[i][j]) path.push_back(j);
            reverse(path.begin(), path.end());
            cout << path.size() << '\n';
            for (auto el : path) {
                cout << el + 1 << ' ';
            }
            return 0;
        }
    }
    cout << "NO LOOP\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dp[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}