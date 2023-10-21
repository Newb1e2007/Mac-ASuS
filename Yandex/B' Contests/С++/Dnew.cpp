#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> fP(n), dE;
    int fP_s = 0;
    vector<pair<int,int>> answ;
    for (int i = 0; i < n; i++) {cin >> fP[i];}
    for (int van = 1; van <= n; van++) {
        if (dE.size() == 0 || dE.back() != van) {
            int ind = fP_s;
            while (fP[fP_s] != van && fP_s < n) {
                dE.push_back(fP[fP_s]);
                fP_s++;
            }
            if (fP[fP_s] != van) {
                cout << 0;
                return 0;
            }
            fP_s++;
            answ.push_back(make_pair(1, fP_s - ind));
            answ.push_back(make_pair(2, 1));
        } else {
            answ.push_back(make_pair(2, 1));
            dE.pop_back();
        }
    }
    cout << answ.size() << '\n';
    for (pair<int, int> p : answ) {
        cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}