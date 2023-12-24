#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n;i ++) {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        int best = 0;
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            if (a[i - 1] == b[j - 1]) {
                if (dp[i - 1][j] < best + 1) {
                    dp[i][j] = best + 1;
                }
            }
            if (a[i - 1] > b[j - 1]) {
                if (dp[i - 1][j] > best) {
                    best = dp[i - 1][j];
                }
            }
        }
    }       
    int pos = 0;
    for (int j = 0; j <= m; j++) {
        if (dp[n][pos] < dp[n][j]) pos = j;
    }
    cout << dp[n][pos] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}