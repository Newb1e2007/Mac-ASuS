#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;
using pli = pair<ll, int>;

void solve() {
    int n; cin >> n;
    vector<ll> L(n), R(n), C(n);
    for (int i = 0; i < n; i++) {
        cin >> L[i];
    }   
    for (int i = 0; i < n; i++) {
        cin >> R[i];
    }   
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }   
    sort(C.begin(), C.end(), greater<ll>());
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    
    vector<pli> arr;
    for (int i = 0; i < n; i++) {
        arr.emplace_back(L[i], i + 1);
        arr.emplace_back(R[i], -i - 1);
    }
    sort(arr.begin(), arr.end());
    vector<ll> sz;
    multiset<ll> lr;
    for (int i = 0; i < (int)arr.size(); i++) {
        if (arr[i].second > 0) {
            lr.insert(arr[i].first);
        } else {
            auto el = prev(lr.end());
            sz.push_back(arr[i].first - *el);
            lr.erase(el);
        }
    }
    
    sort(sz.begin(), sz.end());
    ll answ = 0;
    for (int i = 0; i < n ; i++) {
        answ += sz[i] * C[i]; 
    }
    cout << answ << '\n';
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

/*1861614
  633462
  35824
  609373
  1034901
  1542457*/