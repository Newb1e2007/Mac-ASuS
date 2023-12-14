#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> days(n);
    for (int i = 0; i < n; i++) {
        cin >> days[i];
    }

    int k = 0;
    int curD = 0, lastD = 0;;
    for (int i = 0; i < n; i++) {
        curD = (days[i] - k + m - 1) / m;
        if (lastD != 0 && curD - lastD <= 1) {
            continue;
        } else {
            if (curD - lastD > 2) {
                cout << "-1";
                return;
            }
            k = days[i] - (lastD + 1) * m + k + 1;
            i = 0;
            curD = 0; 
            lastD = 0;
        }
    }
    cout << k - 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; // cin >> t;
    while (t--) solve();

    return 0;
}