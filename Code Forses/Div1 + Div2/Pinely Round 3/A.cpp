#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n; cin >> n;
    map<int, int> pl;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        if (x < 0 && y < 0) {
            pl[4] = 1;
        } else if (x > 0 && y < 0) {
            pl[3] = 1;
        } else if (x < 0 && y > 0) {
            pl[1] = 1;
        } else if (x > 0 && y > 0) {
            pl[2] = 1;
        } else if (x == 0 && y > 0) {
            pl[5] = 1;
        } else if (x == 0 && y < 0) {
            pl[7] = 1;
        } else if (y == 0 && x > 0) {
            pl[6] = 1;
        } else if (y == 0 && x < 0) {
            pl[8] = 1;
        }
    }
    if (pl[1] + pl[2] == 2 && (pl[4] + pl[3] + pl[7] > 0)) {
        cout << "NO\n";
        return;
    } else if (pl[1] + pl[4] == 2 && pl[2] + pl[3] + pl[6] > 0) {
        cout << "NO\n";
        return;
    } else if ((pl[1] + pl[3] == 2) || (pl[2] + pl[4] == 2)) {
        cout << "NO\n";
        return;
    } else if (pl[2] + pl[3] == 2 && pl[1] + pl[4] + pl[8] > 0) {
        cout << "NO\n";
        return;
    } else if (pl[4] + pl[3] == 2 && pl[1] + pl[2] + pl[5] > 0) {
        cout << "NO\n";
        return;
    } else if (pl[5] + pl[6] + pl[7] + pl[8] > 3) {
        cout << "NO\n";
        return;
    } else if (pl[1] == 1 && pl[6] + pl[7] == 2) {
        cout << "NO\n";
        return;
    } else if (pl[2] == 1 && pl[8] + pl[7] == 2) {
        cout << "NO\n";
        return;
    } else if (pl[3] == 1 && pl[5] + pl[8] == 2) {
        cout << "NO\n";
        return;
    } else if (pl[4] == 1 && pl[5] + pl[6] == 2) {
        cout << "NO\n";
        return;
    } else {
        cout << "YES\n";
        return;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}