#include <bits/stdc++.h>

using namespace std;
int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(n, 30000));
    for (int i = 0; i < m; i++) {
        int v, u, w; cin >> v >> u >> w;
        dp[v - 1][u - 1] = w;
    }
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][k] != 30000 && dp[k][j] != 30000 && dp[i][j] != 30000)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}