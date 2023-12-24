#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

void solve() {
    string s; cin >> s;
    if (s[0] == '0') {
        cout << -1 << '\n';
        return;
    }
    string s1 = ""; s1 += s[0];
    int i = 1;

    while(s[i] == '0') {
        s1 += s[i];
        i++;
    }
    string s2 = "";
    if (i == (int)s.length()) {
        cout << -1 << '\n';
        return;
    }
    for (int j = i; j < (int)s.length(); j++) {
        s2 += s[j];
    }
    if (s1 == s2) {
        cout << -1 << '\n';
        return;
    }
    int a = 0;
    int b = 0;
    for (auto c : s1) {
        a *= 10;
        a += c - '0';
    }
    for (auto c : s2) {
        b *= 10;
        b += c - '0';
    }
    if (a >= b) {
        cout << -1 << '\n';
        return;
    }
    cout << s1 << ' ' << s2 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
    
    return 0;
}