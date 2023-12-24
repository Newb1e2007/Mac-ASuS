#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        arr[u - 1]++;
        arr[v - 1]++;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += arr[i] == 1;
    }
    cout << (1 + cnt) / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; 
    while (t--) solve();
    
    return 0;
}