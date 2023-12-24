#include <bits/stdc++.h>

using namespace std;

const int INF = INT32_MAX;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a1, k, b, m; cin >> n >> a1 >> k >> b >> m;
    vector<int> arr(n); arr[0] = a1;
    for (int i = 1; i < n; i++) {
        arr[i] = arr[i - 1] * k + b;
        arr[i] %= m;
    }

    vector<int> dp(n + 1); dp[0] = -INF;
    vector<int> ind(n), prev(n);
    for (int i = 1; i <= n; i++) {
        dp[i] = INF;
    }
    for (int i = 0; i < n; i++) {
        int j = upper_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
        if (j != n + 1) {
            dp[j] = arr[i];
            ind[j] = i;
            prev[i] = ind[j - 1];
        }
    }
    vector<int> answ;
    

    return 0;
}