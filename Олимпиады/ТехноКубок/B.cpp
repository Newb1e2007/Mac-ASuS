#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n & i) continue;
        cnt++;
        if (i * i != n) cnt++;
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while(t--) solve();

    return 0;
}