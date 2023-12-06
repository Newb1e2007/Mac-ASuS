#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n, m; cin >> n >> m;
    vector<pii> events(n);
    vector<int> points(m);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        events.emplace_back(x, -1);
        events.emplace_back(y, 1);
    }
    sort(events.begin(), events.end());
    for (int i = 0; i < m; i++) {
        cin >> points[i];
    }
    sort(points.begin(), points.end());
    int cnt = 0;
    vector<pair<pii, int>> answ;
    int l, r;
    for (pii event : events) {
        cnt += event.second;
        if (event.second == 1) {
            r = event.first;
            answ.emplace_back(l, r, cnt);
        }
        if (event.second == 1) {
            l = event.first;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();

    return 0;
}