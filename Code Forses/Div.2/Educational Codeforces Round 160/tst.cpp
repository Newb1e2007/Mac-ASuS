#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

void solve() {
    string s; cin >> s;
    char c = s[0];
    int n = s[1] - '0';
    for (int i = 0; i < 8; i++) {
        char c1 = 'a' + i;
        if (c != c1)
            cout << c1 << n << '\n';
    }
    for (int i = 1; i <= 8; i++) {
        if (i != n)
            cout << c << i << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
    
    return 0;
}