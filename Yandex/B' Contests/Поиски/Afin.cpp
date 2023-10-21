#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    vector<ll> arr1(n), arr2(m);
    map<ll, vector<ll>> poss;
    for (ll i = 0; i < n; i++) {
        cin >> arr1[i];
        poss[arr1[i]].push_back(i);
    }
    for (ll i = 0; i < m; i++) {
        cin >> arr2[i];
    }
    vector<ll> answer(100000);
    for (auto el : poss) {
        ll beh = 1, answ = 0;
        for (auto pos : el.second) {
            answ = max(beh*(n - 1 - pos - ((ll)el.second.size() - beh)), answ);
            beh++;
        }
        answer[el.first] = answ;
    }
    for (ll hight : arr2) {
        if (poss.count(hight) == 0) {
            cout << 0 << ' ';
        } else {
            cout << answer[hight] << ' ';
        }
    }

    return 0;
}