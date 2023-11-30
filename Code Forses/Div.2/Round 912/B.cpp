#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) cnt++;
        }
    }
    if (cnt > n) {
        cout << "NO\n";
        return;
    } 
    vector<int> answ(n);
    answ[0] = 1;
    cout << "YES\n";
    for (int i = 1; i < n; i++) {
        answ[i] = arr[0][i] | 1;
    }
    for (auto el : answ) cout << el << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}