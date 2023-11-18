#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<ll> pref(n + 1); pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + arr[i - 1];
    }
    ll answ  = 0;
    for (int k = 1;  k <= n; k++) {
        if (n%k != 0) {
            continue;
        } 
        ll maxx = 0;
        ll minn = LONG_LONG_MAX;
        for (int i = k;  i <= n; i += k) {
            maxx = max(maxx, pref[i] - pref[i - k]);
            minn = min(minn, pref[i] - pref[i - k]);
        }
        answ = max(answ, maxx - minn);
    }
    cout << answ << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}