#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;

void solve() {
    int n; cin >> n;
    vector<ll> arr(n);
    map<ll, vector<int>> el_ind;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        el_ind[arr[i]].push_back(i);
    }
    sort(arr.begin(), arr.end());
    vector<ll> pref(n  + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + arr[i - 1];
    }
    int lastDel = -1;
    map<int, int> el_answ;
    for (int i = 0; i < n; i++) {
        if (lastDel >= i) {
            //cout << lastDel << ' ' << i << '\n';
            el_answ[arr[i]] = el_answ[arr[i - 1]];
            continue;
        }
        ll curCnt = pref[i + 1];
        //cout << curCnt << '\n';
        int cnt = i;
        int curEl = i + 1;
        while (curEl < n && arr[curEl] <= curCnt) {
            //cout << "while ";
            cnt++;
            curCnt = pref[curEl + 1];
            //cout << curCnt << ' ' << curEl << '\n';
            curEl++;
        }
        el_answ[arr[i]] = cnt;
        lastDel = curEl - 1;
    }
    vector<int> answ(n);
    for (auto p : el_ind) {
        for (auto ind : p.second) answ[ind] = el_answ[p.first];
        //answ[p.second] = el_answ[p.first];
    }
    for (int i = 0; i < n; i++) {
        cout << answ[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; 
    while (t--) solve();
    
    return 0;
}