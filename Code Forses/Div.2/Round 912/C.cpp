#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
 
/*void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll answ = 0;
    int cnt = 1;
    ll suff = 0;
    ll pref = 0;
    int find = 0;
    int ncnt = 0;
    for (find = 0; find < n; find++) {
        if (arr[find] > 0 && pref >= 0) {
            break;
        }
        pref += (ll)arr[find];
        ncnt++;
    }
    if (ncnt != 0) cnt++;
    int ind = n - 1;
    for (ind = n - 1; ind >= find; ind--) {
        if (suff > 0) {
            break;
        }
        suff += (ll)arr[ind];
    }
    for (int i = find; i <= ind; i++) {
        answ += (ll)cnt * arr[i];
        cnt++;
    }
    answ += pref + suff * (ll)cnt;
    cout << answ << '\n';
}*/

void solve() {
    int n; cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ind = n - 1;
    ll suf = 0;
    for (ind = n - 1; ind >= 0; ind--) {
        if (suf > 0) {
            break;
        }
        suf += (ll)arr[ind];
        arr[ind] = 0;
    }
    arr[ind + 1] = suf;
    vector<ll> suff(n); suff[n  -1] = (ll)arr[n  -1];
    if (n > 1) {
        suff[n - 2] = (ll)arr[n - 2] + (ll)arr[n - 1] * 2;
    }
    for (int i = n - 3; i >= 0; i--) {
        suff[i] = (ll)arr[i] + suff[i + 1] * 2 - suff[i + 2];
    }
    vector<ll> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + (ll)arr[i - 1];
    }
    ll answ = suff[0];
    for (int i = 1; i < n - 1; i++) {
        answ = max(answ, pref[i] + suff[i] * 2 - suff[i + 1]);
    }
    answ = max(answ, pref[n]);
    cout << answ << '\n';
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}