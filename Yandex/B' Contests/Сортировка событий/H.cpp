#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n; cin >> n;
    vector<pii> events;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        events.emplace_back(x, -1);
        events.emplace_back(y, 1);
    }
    sort(events.begin(), events.end());
    int cnt = 0, maxCnt = 0;
    int answ = 0;
    for (pii event : events) {
        cnt += event.second * (-1);
        if (cnt > maxCnt) {
            maxCnt = cnt;
            answ = event.first;
        }
    }
    cout << maxCnt << ' ' << answ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();

    return 0;
}