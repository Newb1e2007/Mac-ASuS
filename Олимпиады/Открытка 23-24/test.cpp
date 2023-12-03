#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n;
    cout << "===============\n";
    cin >> n;
    bitset<(1 << 20)> a(n);
    int sz = a.size();
    cout << sz << '\n';
    int cnt = 0;
    cout << a << '\n';
    for (int i = 0; i < sz; i++) {
        cout << a.test(i) << ' ';
        if (a.test(i) == 1) {
            cnt++;
        } else {
            break;
        }
    }
    cout << '\n' << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}