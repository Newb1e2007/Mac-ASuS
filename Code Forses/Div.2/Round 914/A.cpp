#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;

void solve() {
    int a, b; cin >> a >> b;
    int xk, yk, xq, yq; cin >> xk >> yk >> xq >>  yq;  
    map<pii, int> pos_cnt;
    pii x;
    vector<int> X = {-a, -b, a, b,  a,  b, -a, -b};
    vector<int> Y = { b,  a, b, a, -b, -a, -b, -a};
    for (int i = 0; i < 8;i ++) {
        pos_cnt[{xk + X[i], yk + Y[i]}]++;
        //cout << xk + X[i] << ' ' << yk + Y[i] << '\n';
    }
    int cnt = 0;
    //cout << "==============\n";
    map<pii, int> used;
    for (int i = 0; i < 8;i ++) {
        if (pos_cnt[{xq + X[i], yq + Y[i]}] >= 1 && used[{xq + X[i], yq + Y[i]}] == 0) cnt++;
        used[{xq + X[i], yq + Y[i]}] = 1;
    }
    //cout << "============\n";
    /*for (auto pos : pos_cnt) {
        if (pos.second == 2) {cnt++;
        //cout << pos.first.first << ' ' << pos.first.second << '\n';
        }
    }*/
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; 
    while (t--) solve();
    
    return 0;
}
