#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, w; cin >> n >> w;
    vector<int> W(n), C(n);
    for (int i = 0; i < n; i++) {
        cin >> W[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(w + 1));
    /*for (int i = 1; i <= n; i++) {
            dp[0][i] = -1;
    }*/
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            dp[i][j] = dp[i - 1][j];
            if (W[i - 1] <= j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - W[i - 1]] + C[i - 1]);
            }
        }
    }
    vector<int> answer;
    int x = n, y = w;
    while (dp[x][y] != 0) {
        if (dp[x][y] == dp[x - 1][y]) {
            x--;
        } else {
            answer.push_back(x);
            y -= W[x - 1];
            x--;
        }
    }
    cout << answer.size() << '\n';
    for (int el : answer) {
        cout << el << ' ';
    }
    return 0;
}