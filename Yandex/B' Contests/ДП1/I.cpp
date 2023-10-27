#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, maxW = 0; cin >> n;
    vector<int> W(n);
    for (int i = 0; i < n; i++) {cin >> W[i]; maxW += W[i];}
    if (maxW % 3 == 0) {
        maxW /= 3;
    } else {
        cout << -1;
        return 0;
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(maxW + 1)); dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = maxW; j >= W[i - 1]; j--) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - W[i - 1]];
        }
    }
    if (!dp[n][maxW]) {
        cout << -1;
        return 0;
    }
    map<int, int> W_heaps;
    for (auto w : W) {
        W_heaps[w] = 0;
    }
    int x = n, y = maxW, cnt = 0;
    while (dp[x][y]) {
        if (dp[x - 1][y] == dp[x][y]) {
            x--;
        } else {
            W_heaps[W[x - 1]] = 1;
            cnt++;
            y -= W[x - 1];
            x--;
        }
    }
    vector<int> W1;
    for (auto w : W) {
        if (!W_heaps[w]) {
            W1.push_back(w);
        }
    }

    vector<vector<bool>> dp1(n + 1 - cnt, vector<bool>(maxW + 1)); dp[0][0] = 1;
    for (int i = 1; i <= n - cnt; i++) {
        for (int j = maxW; j >= W1[i - 1]; j--) {
            dp1[i][j] = dp1[i - 1][j] + dp1[i - 1][j - W1[i - 1]];
        }
    }
    if (!dp1[n - cnt][maxW]) {
        cout << -1;
        return 0;
    }
    x = n - cnt;
    y = maxW;
    int cnt1 = 0;
    while (dp1[x][y]) {
        if (dp1[x - 1][y] == dp1[x][y]) {
            x--;
        } else {
            W_heaps[W1[x - 1]] = 2;
            cnt1++;
            y -= W1[x - 1];
            x--;
        }
    }
    cout << cnt << ' ';
    for (auto el : W_heaps) {
        if (el.second == 1) {
            cout << el.first << ' ';
        }
    }
    cout << '\n';
    cout << cnt1 << ' ';
    for (auto el : W_heaps) {
        if (el.second == 2) {
            cout << el.first << ' ';
        }
    }
    cout << '\n';
    cout << n - cnt1 - cnt << ' ';
    for (auto el : W_heaps) {
        if (el.second == 0) {
            cout << el.first << ' ';
        }
    }
    return 0;
}