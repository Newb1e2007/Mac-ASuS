#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (n == 1) {
        cout << 0;
        return;
    }
    int l = 0, r = n - 1;
    ll answ = 0;
    ll summL = 0, summR = 0;
    while (r - l >= 1) {
        summL += (ll)arr[l];
        arr[l] = 0;
        summR += (ll)arr[r];
        arr[r] = 0;
        if (summR == summL) {
            answ = max(answ, summL);
            l++;
        }
        if (summL > summR) {
            r--;
        } 
        if (summL < summR) {
            l++;
        }
    }
    cout << answ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}