#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    int maxDist = arr[0];
    for (int i = 1; i < n; i++) {
        maxDist = max(maxDist, arr[i] - arr[i - 1]);
    }
    cout << max(maxDist, (x - arr.back()) * 2) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}