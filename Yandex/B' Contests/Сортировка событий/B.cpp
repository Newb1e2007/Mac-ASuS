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
    for (int i = 0; i < m; i++) cin >> points[i];
    sort(events.begin(), events.end());

    vector<pii> prefO(n + 1), prefC(n + 1); prefO[0] = {0, 0}; prefC[0] = {0, 0};
    int lastIndO = 0, lastIndC = 0;
    for (int i = 0; i < n*2; i++) {
        //cout << events[i].first << ' ' << events[i].second << '\n';
        if (events[i].second == -1) {
            prefO[lastIndO + 1].second = prefO[lastIndO].second + 1;
            prefO[lastIndO + 1].first = events[i].first;
            lastIndO++;
        } else {
            prefC[lastIndC + 1].second = prefC[lastIndC].second + 1;
            prefC[lastIndC + 1].first = events[i].first;
            lastIndC++;
        }
    }

    /*cout << '\n';
    for (int i = 0; i <= n; i++) {
        cout << prefO[i].first << "; " << prefO[i].second << " | "  << prefC[i].first << "; " << prefC[i].second << '\n';
    }
    cout << '\n';*/

    for (int i = 0; i < m; i++) {
        int indO = 0;
        for (int j = n; j >= 0; j--) {
            if (prefO[j].first <= points[i]) {
                indO = j;
                break;
            }
        }
        int indC = 0;
        for (int j = n; j >= 0; j--) {
            if (prefC[j].first <= points[i]) {
                indC = j;
                break;
            }
        }
        //cout << indO << ' ' << indC << " aboba\n";
        cout << prefO[indO].second - prefC[indC].second << ' ';
    }   
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();

    return 0;
}