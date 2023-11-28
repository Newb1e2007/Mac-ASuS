#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> dp(n + 1); dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1];
        for (int j = 2; j < i && j <= k; j++) {
            dp[i] += dp[i - j];
        }
    }
    cout << dp[n];
    return 0;
}