#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i <n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i< n; i++) {
        cin >> b[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += abs(a[i] - b[i]);
    }
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end());
    if (a[0] - b[0] >= 0) cout << cnt + 2 * (a[0] - b[0]) << '\n';
    else cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
