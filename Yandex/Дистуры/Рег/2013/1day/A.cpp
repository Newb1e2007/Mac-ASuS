#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("casting.in", "r", stdin); freopen("casting.out", "w", stdout);

    int t, n, a, b, c; cin >> t >> n >> a >> b >> c;
    if (t == 1) {
        if (a > 0 && b > 0 && c > 0) cout << (a + b + c) - n * 2;
        else cout << 0;
    } else {
        cout << min(a, min(b, c));
    }
    return 0;
}