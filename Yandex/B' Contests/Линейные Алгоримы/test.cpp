#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
using ui = unsigned int;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> cnt(n);
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        ui l, r; cin >> l >> r;
        int add; cin >> add;
        cnt[l] += add;
        cnt[r] -= add;
    }
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + cnt[i - 1];
    }
    for (int el : pref) {
        cout << el << ' ';
    }
    return 0;
}