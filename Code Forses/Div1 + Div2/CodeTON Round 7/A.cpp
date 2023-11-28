#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, x ;cin >> n >> x;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    //cout << a[0] << ' ' << b[0] << '\n';
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int cnt = 0;
    int j = 0;
    int firstGoodInd = 0;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        if (a[i] > b[j]) {
            arr[i] = {a[i], b[j]};
            j++;
            cnt++;
        } else {
            firstGoodInd++;
        }
    }
    if (cnt == x) {
        cout << "YES\n";
        int ind = n - 1;
        for (int i = 0; i < firstGoodInd; i++) {
            arr[i] = {a[i], b[ind]};
            ind--;
        }
        for (int i = 0; i < n; i++) {
            cout << arr[i].second << ' ';
        }
        cout << '\n';
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}