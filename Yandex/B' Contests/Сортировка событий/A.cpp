#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n; cin >> n;
    vector<pii> events(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        events.emplace_back(x, -1);
        events.emplace_back(y, 1);
    }
    sort(events.begin(), events.end());
    int cnt = 0;
    vector<pii> answ;
    int l, r;
    for (pii event : events) {
        if (cnt == 0 && event.second == -1) {
            l = event.first;
        }
        cnt += event.second;
        if (cnt == 0 && event.second == 1) {
            r = event.first;
            answ.emplace_back(l, r);
        }
    }
    cout << answ.size() << '\n';
    for (pii p : answ) {
        cout << p.first << ' ' << p.second << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();

    return 0;
}