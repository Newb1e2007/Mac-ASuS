#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n, k; cin >> n >> k;
    if (n > 1 && k == 1) {cout << -1; return;}
    vector<int> answ(n);
    //int fEl = n - k + 1;
    //answ[0] = fEl;
    int ind = 0;
    int m = n;
    while (ind < n) {
        int fEl;
        if (m < k) fEl = 1;
        else fEl = m - k + 1;
        //answ[ind] = fEl;
        //ind++;
        int cnt = 0;
        for (fEl = fEl; fEl <= m && cnt < k && ind < n; fEl++) {
            answ[ind] = fEl;
            ind++; cnt++;
        }
        m -= k;
    }
    for (auto el : answ) cout << el << ' ';
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}