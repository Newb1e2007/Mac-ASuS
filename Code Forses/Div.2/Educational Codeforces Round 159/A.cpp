#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    bool canWe = false;
    int cntZ = 0, cntO = 0;
    if (s[0] == '0') cntZ++; 
    else cntO++;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) canWe = true;
        if (s[i] == '0') cntZ++;
        else cntO++;
    }
    if (canWe || cntZ > cntO) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}