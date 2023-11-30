#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int gcd(int a, int b) {
    if (b ==  0) return a;
    return gcd(b, a % b);
}

/*void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    for (int i = 0; i <= 100000; i++) {
        if ((b + a * i - d > 0) && (b + a * i - d) % c == 0) {
            cout << b + a*i;
            return;
        }
    }
    cout << -1;
}*/

void solve() {
    ll l, r; cin >> l >> r;
    cout << "YES\n";
    for (ll i = l; i <= r; i += 2) {
        cout << i << ' ' << i + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}