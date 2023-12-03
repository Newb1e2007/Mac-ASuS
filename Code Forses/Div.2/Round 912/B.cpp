#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    vector<int> els(n, (1<<30) - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (i == j) continue;
            els[i] &= arr[i][j];
            els[j] &= arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && (els[i] | els[j]) != arr[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    }    
    cout << "YES\n";
    for (int el : els) cout << el << ' ';
    cout << '\n';    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}