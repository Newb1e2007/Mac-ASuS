#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    ll a, b, c, d; cin >> a >> b >> c >> d;

    ll answ = 0;
    for (ll i = 1; i * i <= b; i++) {
        for (ll j = 1; j * i <= b; j++) {
            if (i * j >= a && 2 * (i + j) >= c && 2 * (i + j) <= d && i <= j) {
                //cout << i << ' ' << j << '\n';
                answ++;
            }
        }
    }
    cout << answ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}