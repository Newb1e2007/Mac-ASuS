#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ull = unsigned long long;
using ld = long double;

struct Node {
    vector<int> els;
};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> next(n);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a + i <= n - 1) {
            next[i] = i + a;
        } else {
            next[i] = i;
        }
    }
    vector<pii> suff(n);
    for (int i = 0; i < n; i++ ) {
        suff[i].second = i;
    }
    for (int i = n - 1; i >= 0; i--) {
        suff[i].first = suff[next[i]].first + 1;
        suff[i].second = suff[next[i]].second;
    }

    for (int i = 0; i < m; i++) {
        int t; cin >> t;
        if (t == 0) {
            int a, b; cin >> a >> b;
            if (a - 1 + b <= n - 1) {
                next[a - 1] = a - 1 + b;    
                suff[a - 1].first = suff[next[a - 1]].first + 1;
                suff[a - 1].second = suff[next[a - 1]].second;
            } else {
                next[a - 1] = a - 1;
                suff[a - 1].first = 1;
                suff[a - 1].second = a - 1;
            }
        } else {
            int a; cin >> a;
            cout << suff[a - 1].second + 1 << ' ' << suff[a - 1].first << '\n';
        }
    }
    for (int i = 0; i < n; i++) {
        cout << suff[i].first << ' ' << suff[i].second << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}
