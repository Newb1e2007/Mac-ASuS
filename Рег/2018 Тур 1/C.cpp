#include <bits/stdc++.h>

#define int long long

using namespace std;
//using int = long long;
using pii = pair<int, int>;

void solve() {
    int n, m; cin >> n >> m;
    //vector<pii> arr(n);
    vector<pair<pii, int>> events;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        //arr[i] = {a, b};
        //events.emplace_back(a, b, i);
        events.push_back({{a, b}, i});
    }
    sort(events.begin(), events.end());

    vector<int> answ(n);
    int allTime = 0;
    int maxPos = 1; // то, откуда я начал спускаться
    int pos = 1;
    int upTime = 0;
    vector<pair<pii, int>> curV;
    //int lastEv = -1;
    /*for (pair<pii, int> event : events) {
        if (pos > event.first.second) {
            if (pos - event.first.second + upTime >= event.first.first) {
                //answ[event.second] = allTime + pos - 1 + upTime;
                curV.push_back(event);
            } else {
                allTime += pos - 1 + upTime;
                pos = event.first.second;
                upTime = event.first.second - 1;
                answ[event.second] = allTime + pos - 1 + upTime;
            }
        } else {
            allTime += pos - 1 + upTime;
            pos = event.first.second;
            upTime = event.first.second - 1;
            answ[event.second] = allTime + pos - 1 + upTime;
        }
    }*/
    int last = 1e9;
    for (int e = 0; e < n; e++) {
        if (pos < events[e].first.second || pos - events[e].first.second < events[e].first.first) {
            last = min(last, e);
        } else {
            answ[events[e].second] = allTime + 2 * upTime;
        }
    }
    for (auto el : answ) cout << el << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}