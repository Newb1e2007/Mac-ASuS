#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n, a, b; cin >> n >> a >> b;
    vector<int> arr(n);
    int maxEl = -1e9;
    map<int, int> el_cnt;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxEl = max(maxEl, arr[i]);
        el_cnt[arr[i]]++;
    }
    if (a < b) {
        if (el_cnt[maxEl] != n) {
            cout << (maxEl + b - 1) / b;
            return;
        } else {
            int tmp = 
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}