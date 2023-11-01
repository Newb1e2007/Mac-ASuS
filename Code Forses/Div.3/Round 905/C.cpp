#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, cnt = 0; cin >> n >> k;
    int minDif = 1e9;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x % 2 == 1) cnt++;
        minDif = min(minDif, (int)(ceil(static_cast<double>(x) / k) * k - x));
    }
    if (k == 4) {
        if (n - cnt >= 2) {
            std::cout << 0 << '\n';
            return;
        } else if (n - cnt == 1 ) {
            std::cout << min(minDif, 1) << '\n';
            return;
        } else if (cnt >= 2) {
            std::cout << min(minDif, 2) << '\n';
            return;
        }
    }
    std::cout << minDif << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}