#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n, m; cin >> n >> m;
    vector<pii> events;
    vector<int> points(m);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        if (x > y) swap(x, y);
        events.emplace_back(x, -1);
        events.emplace_back(y, 1);
    }
    for (int i = 0; i < m; i++) {
        int mi; cin >> mi;
        points[i] = mi;
        events.emplace_back(mi, 0);
    }
    //int sz= points.size();
    //sort(newPoints.begin(), newPoints.end());
    sort(events.begin(), events.end());
    int cnt = 0;
    //int ind = 0;
    map<int, int> answ;
    for (pii event : events) {
        cnt += -event.second;
        if (event.second == 0) {
            answ[event.first] = cnt;
        }
    }   
    for (int p : points) {
        cout << answ[p] << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();

    return 0;
}