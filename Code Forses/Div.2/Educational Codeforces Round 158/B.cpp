#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    ll answ = arr[0] - 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            answ += arr[i] - arr[i - 1];
        }
    }
    cout << answ << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}