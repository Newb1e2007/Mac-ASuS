#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, w;
    cin >> n >> w;
    vector < int > W(n);
    for (int i = 0; i < n; i++) {
        cin >> W[i];
    }
    bitset < 10000000 > dp;
    dp.reset();
    dp.set(0);
    for (int i = 1; i <= n; i++) {
        dp |= (dp << (W[i - 1]));
    }
    if (dp.test(w)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
