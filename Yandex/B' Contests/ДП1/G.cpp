#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, maxW = 0; cin >> n;
    vector<int> W(n);
    for (int i = 0; i < n; i++) {cin >> W[i]; maxW += W[i];}
    if (maxW % 2 == 0 && n % 2 == 0) {
        maxW/=2;
    } else {
        cout << -1;
        return 0;
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(maxW + 1)); dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = maxW; j >= 0; j--) {
            dp[i][j] = dp[i - 1][j];
            if (j >= W[i - 1]) {
                dp[i][j] = dp[i][j] + dp[i - 1][j - W[i - 1]];
            }
        }
    }
    if (!dp[n][maxW]) {
        cout << -1;
        return 0;
    }
    int i = n;
    map<int, int> WInd_heap;
    while (dp[i--][maxW] != 0) {
        int x = i, y = maxW, cnt = 0;
        for (int i = 1; i <= n; i++) {
            WInd_heap[i] = 0;
        }
        while (x != 0) {
            if (y >= W[x - 1] && dp[x - 1][y - W[x - 1]]) {
                cnt++;
                WInd_heap[x] = 1;
                y -= W[x - 1];
                x--;
            } else {
                /*if (dp[x - 1][y]) {
                    x--;
                } else {
                    break;
                }*/
                x--;
            }
        }
        if (cnt*2 == n) {
            for (auto el : WInd_heap) {
                if (el.second == 1) {
                    cout << el.first << ' ';
                }
            }
            cout << '\n';
            for (auto el : WInd_heap) {
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