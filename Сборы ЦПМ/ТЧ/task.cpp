#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    for (int i = 0; i <= 100; i++) {
        if ((b + a * i - d > 0) && (b + a * i - d) % c == 0) {
            cout << b + a*i;
            return;
        }
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}