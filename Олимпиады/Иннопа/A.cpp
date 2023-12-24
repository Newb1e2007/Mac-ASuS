#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ld = long double;

void solve() {
    int n, q; ll x; cin >> n >> q >> x;
    x *= 100;
    //vector<int> arr(n);
    vector<ll> arr(q);
    for (int i = 0; i < n; i++) {
        int t; ll m, k; cin >> t >> m >> k;
        arr[t - 1] += m * k; 
    }
    sort(arr.begin(), arr.end(), greater<ll>());
    int cnt = 0;
    ll res = 0;
    for (int i = 0; i < q; i++) {
        cnt++;
        res += arr[i];
        if (res >= x) {
            break;
        }
    }
    if (res >= x) {
        cout << cnt;
    } else {
        cout << -1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while(t--) solve();

    return 0;
}