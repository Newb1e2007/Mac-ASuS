#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<pair<int, int>> findLR(vector<int>& hs, int n) {
    vector<pair<int, int>> answ(n);
    vector<pair<int, int>> st;
    for (int i = n - 1; i >= 0; i--) {
        while(!st.empty() && st.back().first >= hs[i]) {
            st.pop_back();
        }
        if (!st.empty()) {
            answ[i].second = st.back().second;
        }
        st.push_back(make_pair(hs[i], i));
    }
    vector<pair<int, int>> stn;
    for (int i = 0; i < n; i++) {
        while(!stn.empty() && stn.back().first >= hs[i]) {
            stn.pop_back();
        }
        if (!stn.empty()) {
            answ[i].first = stn.back().second;
        }
        stn.push_back(make_pair(hs[i], i));
    }
    return answ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> hs(n);
    for (int i = 0; i < n; i++) {
        cin >> hs[i];
    }
    ll answ = 0;
    vector<pair<int, int>> lr = findLR(hs, n);
    for (int i = 0; i < n; i++) {
        if (lr[i].second == 0) lr[i].second = n;
        if (lr[i].first == 0 && hs[i] <= hs[0]) lr[i].first = -1;
        //int dist = lr[i].second - lr[i].first - 1;
        //if (lr[i].first == 0 && lr[i].second) lr[i].second - lr[i].first - 1 = 1; 
        ll newAnsw = (ll)hs[i] * (ll)(lr[i].second - lr[i].first - 1);
        answ = max(answ, newAnsw);
        //cout << answ << ' ' << i << ' ' << lr[i].second << ' ' << lr[i].first << '\n'; 
    }
    cout << answ;

    return 0;
}