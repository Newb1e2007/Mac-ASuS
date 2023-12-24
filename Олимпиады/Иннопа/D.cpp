#include <bits/stdc++.h>
#include <bitset>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

void solve() {
    int t; cin >> t;
    if (t == 1) {
        int n; cin >> n;
        vector<int> P(n);
        for (int i = 0; i < n; i++) {
            cin >> P[i];
        }
        string s = "";
        //string add = "";
        for (int i = 0; i < n; i++) {
            bitset<64> K(P[i]);
            s += K.to_string();
            //if (i != n - 1)
            //    s += add;
            //add += "0";
        }
        cout << s << '\n';
    } else {
        int n; cin >> n;
        vector<int> Q(n);
        for (int i = 0; i < n; i++) {
            cin >> Q[i];
        }
        string s; cin >> s;
        //int add = 0;
        vector<int> answ;
        for (int i = 0; i < int(s.length()); i += 64) {
            string ss = "";
            for (int j = i; j < i + 64; j++) {
                ss += s[j];
            } 
            bitset<64> K(ss);
            auto val = K.to_ullong();
            int nVal = static_cast<int>(val);
            answ.push_back(nVal);
            //i += add;
            //add++;
        }
        for (int i = 0; i < n; i++) {
            cout << answ[i] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while(t--) solve();

    return 0;
}