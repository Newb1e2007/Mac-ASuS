#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, w; cin >> n >> w;
    int maxC = 0;
    vector<int> W(n), C(n);
    for (int i = 0; i < n; i++) {
        cin >> W[i] >> C[i]; maxC += C[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(maxC + 1));
    for (int i = 1; i <= maxC; i++) {dp[0][i] = 1e9;}
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= maxC; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= C[i - 1]) {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - C[i - 1]] + W[i - 1]);
            }
        }
    }

    int i = n, j = maxC;
    while (dp[i][j] > w) {
        if (i > 1) {i--;}
        else {i = n; j--;}
    }
    cout << j << '\n';
    vector<int> answer;
    int x = i, y = j;
    while (dp[x][y] != 0) {
        if (dp[x][y] == dp[x - 1][y]) {
            x--;
        } else {
            answer.push_back(x);
            y -= C[x - 1]; x--;
        } 
    }
    cout << answer.size() << '\n';
    for (int el : answer) {
        cout << el << ' ';
    }
    return 0;
}