#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    int sz1 = s1.length();
    int sz2 = s2.length();
    vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1));
    for (int i = 0; i <= sz1; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= sz2; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= sz1; i++) {
        for (int j = 1; j <= sz2; j++) {
            dp[i][j] = min(dp[i][j - 1] + 1, dp[i - 1][j] + 1);
            if (s1[i - 1] == s2[j - 1]) {
                //cout << i << ' ' << j << ' ' << dp[i - 1][j - 1] << '\n';
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]); 
            } else {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1); 
            }
        }
    }

    cout << dp[sz1][sz2];
    return 0;
}