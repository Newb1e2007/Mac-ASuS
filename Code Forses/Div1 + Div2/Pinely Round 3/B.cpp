#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n; cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll mod = 1;
    while (true) {
        int cnt = 0;
        map<ll, int> els;
        for (int i = 0; i < n; i++) {
            if (els[arr[i] % mod] == 0) {
                cnt++;
            }
            els[arr[i] % mod]++;
        }
        if (cnt == 2) {
            cout << mod << '\n';
            return;
        }
        mod <<= 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}