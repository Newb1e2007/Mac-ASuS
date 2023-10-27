#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, maxW = 0; cin >> n;
    vector<pair<int, int>> W(n);
    for (int i = 0; i < n; i++) {cin >> W[i].first; W[i].second = i + 1; maxW += W[i].first;}
    if (maxW % 3 == 0) {
        maxW /= 3;
    } else {
        cout << -1;
        return 0;
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(maxW + 1)); dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = maxW; j >= 0; j--) {
            dp[i][j] = dp[i - 1][j];
            if (j >= W[i - 1].first) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - W[i - 1].first];
            }
        }
    }
    if (!dp[n][maxW]) {
        cout << -1;
        return 0;
    }
    map<int, int> W_heaps;
    int i = n, j = maxW;
    while (dp[i--][j] != 0) {
        for (int i = 1; i <= n; i++) {
            W_heaps[i] = 0;
        }
        int x = i, y = maxW;
        int cnt = 0;
        while (x != 0) {
            if (y >= W[x - 1].first && dp[x - 1][y - W[x - 1].first]) {
                W_heaps[W[x - 1].second] = 1;
                cnt++;
                y -= W[x - 1].first;
                x--;
            } else {
                x--;
            }
        }
        if (cnt == 0) {
            cout << -1;
            return 0;
        }
        vector<pair<int, int>> W1;
        for (auto w : W) {
            if (!W_heaps[w.second]) {
                W1.push_back(w);
            }
        }

        vector<vector<bool>> dp1(n + 1 - cnt, vector<bool>(maxW + 1)); dp1[0][0] = 1;
        for (int i = 1; i <= n - cnt; i++) {
            for (int j = maxW; j >= 0; j--) {
                dp1[i][j] = dp1[i - 1][j];
                if (j >= W1[i - 1].first) {
                    dp1[i][j] = dp1[i - 1][j] + dp1[i - 1][j - W1[i - 1].first];
                }
            }
        }
        if (dp1[n - cnt][maxW]) {
            x = n - cnt;
            y = maxW;
            int cnt1 = 0;
            while (x != 0) {
                if (y >= W1[x - 1].first && dp1[x - 1][y - W1[x - 1].first]) {
                    W_heaps[W1[x - 1].second] = 2;
                    cnt1++;
                    y -= W1[x - 1].first;
                    x--;
                } else {
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
    }
    cout << -1;
    return 0;
}