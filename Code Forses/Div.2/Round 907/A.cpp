#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 2; i < n - 1; i += 2) {
        if (arr[i] > arr[i + 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}