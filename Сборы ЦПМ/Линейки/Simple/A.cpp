#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<ll> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = (ll)arr[i - 1] + (ll)pref[i - 1];
    }
    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        int l, r; cin >> l >> r;
        cout << pref[r] - pref[l - 1] << ' ';
    }

    return 0;
}