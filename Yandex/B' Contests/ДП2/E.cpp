#include <bits/stdc++.h>

using namespace std;

int main() {
    int s; cin >> s;
    vector<vector<vector<int>>> dp(10, vector<vector<int>>(s + 1, vector<int>(10)));
    for (int i = 1; i <= 9 && i <= s; i++) {
        cout << i << ' ';
        dp[1][i][i] = 1;
    }
    cout << "\n\n";

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= s; j++) {
            for (int k = 1; k <= 9; k++) {
                for (int kn = 1; kn <= 9; kn++) {
                    if (j >= k) {
                        //cout << "if\n";
                        dp[i][j][k] += dp[i - 1][j - k][kn];
                    }
                    if (kn < k && j >= (k - kn)) {
                        //cout << "else\n";
                        dp[i][j][k] += dp[i][j - (k - kn)][kn];
                    }
                }   
            }
        }
    }
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= s; j++) {
            cout << "{";
            for (int k = 0; k <= 9; k++) {
                cout << dp[i][j][k] << ' ';
            }
            cout << "} ";
        }
        cout << '\n';
    }
    int summ = 0;
    for (int i = 1; i <= 9; i++) {
        summ += dp[9][s][i];
    }
    cout << summ;
    return 0;
}