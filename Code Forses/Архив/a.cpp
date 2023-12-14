#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int answ = 0;
    map<char, int> el_cnt;
    for (int i = 0; i < n; i++) {
        el_cnt[s[i]]++;
    }
    for (auto c : el_cnt) {
        if (c.second > n / 2) {
            answ = c.second - (n - c.second);
        }
    }
    
    cout << max(answ, n % 2) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; 
    while (t--) solve();
    
    return 0;
}
