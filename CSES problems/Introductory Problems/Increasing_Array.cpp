#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ull prev, cnt = 0; cin >> n >> prev;

    for (int i = 1; i < n; i++) {
        ull x; cin >> x;
        if (x < prev) cnt += prev - x;
        else prev = x;
    }
    cout << cnt;
    return 0;
}