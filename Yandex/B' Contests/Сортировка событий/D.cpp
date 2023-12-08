#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair < int, int >;

struct Event {
    int x;
    int type;
    int num;

    Event(int x1, int type1, int num1) {
        x = x1;
        type = type1;
        num = num1;
    }
};

void solve() {
    int n;
    cin >> n;
    vector < Event > events;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        Event a(x, 1, i);
        Event b(y, -1, i);
        events.push_back(a);
        events.push_back(b);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();

    return 0;
}