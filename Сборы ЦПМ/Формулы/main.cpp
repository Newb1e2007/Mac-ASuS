#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int da, db; cin >> da >> db;
    if (da == db) {
        cout << da * 10 + 1 << ' ' << da*10 + 2;
    } else if (db - da == 1) {
        cout << da << ' ' << db;
    } else if (da - db == 8) {
        cout << 9 << ' ' << 10;
    } else {
       cout << -1;
    }
}

/*void solve() {
    int a, b, n, s; cin >> a >> b >> n >> s;
    if (s / n > a) {
        if (s - a * n > b) cout << "NO\n";
        else cout << "YES\n";
    } else if (s % n > b) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;   
}