#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>; 
using ll = long long;

void solve() {
    string s; cin >> s;
    int cnt = 0;
    for (auto c : s) {
        if (c == '0') {
            cnt++;
        }
    }
    int sz = s.length();
    if (sz == 1) {
        cout << 1 << '\n';
        return;
    }
    if (sz - cnt == cnt) {
        cout << 0 << '\n';
        return;
    }
    if (cnt == sz || cnt == 0) {
        cout << sz << '\n';
        return;
    }
    string s2 = s;
    int ind = 0;
    int cnt1 = cnt;
    while (ind < sz && cnt1 > 0) {
        if (s2[ind] == '1') {s[ind] = '0'; cnt1--;}
        ind++;
    }
    int ind2 = 0;
    int cnt2 = cnt;
    while (ind2 < sz && cnt2 > 0) {
        if (s2[ind2] == '0') {s[ind2] = '1'; cnt2--;}
        ind2++;
    }
    int ind3 = 0;
    for (ind3 = 0; ind3 < sz; ind3++) {
        if (s2[ind3] == s[ind3]) {
            break;
        }
    }
    cout << sz - ind3 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
    
    return 0;
}