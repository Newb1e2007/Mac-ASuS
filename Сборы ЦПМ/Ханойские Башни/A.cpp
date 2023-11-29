#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

void rek(int n, int i, int j) {
    if (n == 0) return;
    int free = 6 - i - j;
    if ((i == 1 && j != 2) || (i == 2 && j != 3) || (i == 3 && j != 1)) {
        rek(n - 1, i, free);
        cout << n << ' ' << i << ' ' << free << '\n';
        rek(n - 1, j, i);
        cout << n << ' ' << free << ' ' << j << '\n';
        rek(n - 1, i, j);
    } else {
        rek(n - 1, i, free);
        cout << n << ' ' << i << ' ' << j << '\n';
        rek(n - 1, free, j);
    }
}

/*void rek(int n, int i) {
    if (n == 0) return;
    int j;
    if ((i == 1 && j == 3) || (i == 3 && j == 1)) {
        rek(n, i, 2);
        //cout << n << ' ' << i << ' ' << 2 << '\n';
        rek(n, 2, j);
    } else {
        rek(n - 1, i, free);
        cout << n << ' ' << i << ' ' << j << '\n';
        rek(n - 1, free, j);
    }
    if (n % 2 == 1) {
        j = 2;
        simpleRek(n, i, j);
    } else {
        j = 3;
        simpleRek(n, i, j);
    }
    rek(n - 1, j);
}*/

void solve() {
    int n; cin >> n;
    rek(n, 1, 3);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}