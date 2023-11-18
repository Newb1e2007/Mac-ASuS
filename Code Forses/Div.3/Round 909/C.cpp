#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n; 
    int maxSumm = 0;
    int curSumm = 0;
    bool lastCh = false;
    int a; cin >> a;
    int i = 1;
    maxSumm = a;
    while (a < 0 && i < n) {
        cin >> a;
        maxSumm = max(maxSumm, a);
    }
    if (a == n - 1) {
        cout << maxSumm << '\n';
        return;
    }
    bool lastCh = a % 2; 
    curSumm = a;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a%2 != lastCh) {
            if (a < 0) {
                maxSumm = max(curSumm, maxSumm);
                if (curSumm - abs(a) > 0) {
                    curSumm += a;
                    lastCh = a % 2;
                    continue;
                } else {
                    curSumm = 0;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}