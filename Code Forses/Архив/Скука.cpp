#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    map<int, int> el_cnt;
    vector<int> arr(n);
    int maxel = 0;
    for (int i = 0; i <n; i++) {
        int a; cin >> a;
        arr[i] = a;
        el_cnt[a]++;
        maxel = max(maxel, a);
    }
    sort(arr.begin(), arr.end());
    vector<int> dp(maxel + 1);
    dp[arr[0]] = el_cnt[arr[0]];
    for (int i = 1; i < n; i++) {
        dp[arr[i]] = max(dp[arr[i] - 1], dp[arr[i] - 2] + el_cnt[arr[i]]*arr[i]);
    }
    cout << dp[arr.back()];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();    

    return 0;
}