#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

void rek(int n, int i, int j) {
    if (n == 0) return;
    int free = 6 - i - j;
    rek(n - 1, i, free);
    cout << n << ' ' << i << ' ' << j << '\n';
    rek(n - 1, free, j);
}

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