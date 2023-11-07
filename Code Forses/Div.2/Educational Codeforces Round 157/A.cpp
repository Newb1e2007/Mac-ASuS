#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y, k; cin >> x >> y >> k;
    if (y <= x) {
        cout << x << '\n';
    } else if (x < y) {
        if (k < y - x) {
            cout << min(x + k + 2*(y - x - k), x + 2*(y - x)) << '\n';
        } else {
            cout << y << '\n';
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
