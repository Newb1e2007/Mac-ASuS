#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, w; cin >> n >> w;
    vector<int> W(n), C(n);
    for (int i = 0; i < n; i++) {
        cin >> W[i]; cin >> C[i];
    }
    //vector<int> dp(w + 1);
    vector<int> dp(w + 1);
    vector<vector<bool>> cond(n + 1, vector<bool> (w + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = w; j >= W[i - 1]; j--) {
            cond[i][j] = false;
            if (dp[j] < dp[j - W[i - 1]] + C[i - 1]) {
                dp[j] = dp[j - W[i - 1]] + C[i - 1];
                cond[i][j] = true;
            }
            //dp[j] = max(dp[j], dp[j - W[i - 1]] + C[i - 1]);
        }
    }
    /*for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (W[i - 1] <= j && dp[j] < dp[j - W[i - 1]] + C[i - 1]) {
                dp[j] = dp[j - W[i - 1]] + C[i - 1];
                answer.push_back(i - 1);
            }
        }
    }*/
    cout << dp[w] << '\n';
    int cnt = 0;
    vector<int> answ;
    int j = w;
    for (int i = n; i > 0; i--) {
        if (cond[i][j]) {
            cnt++; j -= W[i - 1]; answ.push_back(i);
        }
    }
    /*for (int i = 1; i <= n; i++) {
        if (cond[i][j]) {
            answ.push_back(i); w -= W[i - 1]; 
        }
    }*/

    cout << cnt << '\n';
    for (int el : answ) {
        cout << el << ' ';
    }
    return 0;
}