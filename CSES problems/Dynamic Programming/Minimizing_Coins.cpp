#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x; cin >> n >> x;
    vector<int> C(n);
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }
    vector<int> dp(x + 1); for (int i = 1; i <= x; i++) {dp[i] = 1e9;}
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            if (j >= C[i - 1]) {
                dp[j] = min(dp[j], dp[j - C[i - 1]] + 1);
            }
        }
    }
    if (dp[x] == 1e9) {
        cout << -1;
    } else {
        cout << dp[x];
    }
    return 0;
}