#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n; cin >> n;
    //vector<pii> arr(n);
    priority_queue<pii> arr;
    int maxDay = 0;
    for (int i = 0; i < n; i++) {
        int d, w; cin >> d >> w;
        arr.push({d, w});
        maxDay = max(maxDay, d);
    }
    ll answ = 0;
    int day = maxDay;
    for (day = maxDay; day > 0; day--) {
        if (arr.empty()) break;
        pii newTask = arr.top();
        if (newTask.first >= day) arr.pop();
    }
    while(!arr.empty()) {
        pii a = arr.top();
        answ += (ll)a.second;
        arr.pop();
    }
    cout << answ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}