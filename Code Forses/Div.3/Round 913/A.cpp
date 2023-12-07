#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n; cin >> n;
    string cond; cin >> cond;
    vector<pii> graph(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        graph[i] = make_pair(x, cond[i] - '0');
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}