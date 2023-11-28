#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b; cin >> a >> b;
    cout << abs(b - a) / 5 + (abs(b - a) % 5) / 2 + (abs(b - a) % 5) % 2 << '\n'; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}