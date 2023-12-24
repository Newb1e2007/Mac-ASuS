#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m; cin >> m;
    vector<int> degs(30);
    ll allSumm = 0;
    for (int i = 0; i < m; i++) {
        int t; cin >> t;
        if (t == 1) {
            int v; cin >> v;
            if (v == 0) {
                degs[v]++;
                continue;
            } 
            while (v <= 29 && degs[v] == 1 ) {
                v++;
            }
            if (v <= 29) {
                degs[v]++;
            } else {
                degs[29]++;
            }
        } else {
            int w; cin >> w;
            if (w % 2 == 1) {
                if (degs[0] == 0) {
                    cout << "NO\n";
                    continue;
                }
            }
            int res = 1;
            int cnt = 0;
            while (res * 2 <= w) {
                cnt++;
                res *= 2;
            }
            if (res == w) {
                bool flag = false;
                for (int i = cnt; i < 30; i++) {
                    if (degs[i] > 0) {
                        flag = true;
                        break;
                    }
                }
                if (flag) {
                    cout << "YES\n";
                    continue;
                }
                
            }
        }
    }
}