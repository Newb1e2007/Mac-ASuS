#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

/*void rek(string s, int l, int cnt) {
    if (l == 0) {
        cout << s << '\n';
        return;
    }
    if (l == k - cnt) {
        for (int i = 0; i < l; i++) {
            
        }
    }
    l--;
    for (int i = 0; i < k; i++) {
        rek(s + to_string(i), l);
    }
}*/

void solve() {
    int n; cin >> n;
    string s = "";
    for (int i = 1; i <= n; i++) s += to_string(i);
    cout << s << '\n';
    //iota(arr.begin(), arr.end(), 1);
    while (next_permutation(s.begin(), s.end())) {
        cout << s << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}