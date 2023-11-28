#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i <n; i++) {
        cin >> arr[i];
    }
    vector<int> pref(n), suff(n);
    for (int i = 0; i < n; i++) {
        pref[i] = arr[i] + (n - i - 1);
        suff[i] = arr[i] + i;
    }
    for (int i = 1, j = n - 2; i < n && j >= 0; i++, j--) {
        pref[i] = max(pref[i - 1], pref[i]);
        suff[j] = max(suff[j + 1], suff[j]);
    }
    int answ = INT32_MAX;
    for (int i = 0; i < n; i++) {
        int cur = arr[i];
        if (i > 0) cur = max(cur, pref[i - 1]);
        if (i < n - 1) cur = max(cur, suff[i + 1]);
        answ = min(answ, cur);
    }
    cout << answ;
}

/*
    vector<int> pref(n), suf(n);
    for (int i = 0; i < n; ++i) {
        pref[i] = a[i] + (n - i - 1);
        suf[i] = a[i] + i;
    }
    for (int i = 1; i < n; ++i) {
        pref[i] = max(pref[i], pref[i - 1]);
    }
    for (int i = n - 2; i >= 0; --i) {
        suf[i] = max(suf[i], suf[i + 1]);
    }
    
    int ans = 2e9;
    for (int i = 0; i < n; ++i) {
        int cur = a[i];
        if (i > 0) cur = max(cur, pref[i - 1]);
        if (i + 1 < n) cur = max(cur, suf[i + 1]);
        ans = min(ans, cur);
    }
    
    cout << ans << endl;
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;// cin >> t;
    while(t--) solve();
    return 0;
}
