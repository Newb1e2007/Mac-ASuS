#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> t(n, vector<int>(m));
    for (int i = 0 ; i < n; i++) {
        string s; cin >> s;
        for (int j = 0 ; j < m; j++) {
            t[i][j] = s[j] - '0';
        }
    } 
    if (n == 1 || m == 1) {
        cout << '?';
        return;
    }
    int cntV = 0, cntG = 0;
    int distV = 0, distG = 0;
    int lastV = 0, lastG = 0;
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < m; j++) {
            if (t[i][j] != 1) {
                flag = false;
                break;
            }
        }
        if (flag) {
            if (cntG == 0) lastG = i;
            if (cntG == 1) distG = i - lastG - 1;
            cntG++;
        }
    }
    for (int i = 0; i < m; i++) {
        bool flag = true;
        for (int j = 0; j < n; j++) {
            //cout << i << ' ' << j << "\n";
            if (t[j][i] != 1) {
                flag = false;
                break;
            }
        }
        if (flag) {
            if (cntV == 0) lastV = i;
            if (cntV == 1) distV = i - lastV - 1;
            cntV++;
        }
    }
    if (cntG >= 1 && cntV >= 1) {
        cout << "Square";
    } else if (cntG > 1 && distG < n && distG < m) {
        cout << "Line";
    } else if (cntV > 1 && distV < m && distV < n) {
        //cout << distV;
        cout << "Vertical Line";
    } else {
        cout << "?";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}