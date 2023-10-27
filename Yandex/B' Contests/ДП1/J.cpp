#include <bits/stdc++.h>

using namespace std;
using bs = bitset<10000000>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, maxW = 0; cin >> n;
    vector<int> W(n);
    for (int i = 0; i < n; i++) {cin >> W[i]; maxW += W[i];}
    if (maxW % 2 == 0) {
        maxW/=2;
    } else {
        cout << "NO";
        return 0;
    }
    bs dp;
    dp.reset();
    dp.set(0);
    for (int i = 1; i <= n; i++) {
        dp |= (dp << W[i - 1]);
    }
    if (dp.test(maxW)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;    
}