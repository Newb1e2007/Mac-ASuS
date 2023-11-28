#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    int cnt = 0, j = 0;
    vector<int> arr(n, -1);
    for (int i = 0; i < n; i++) {
        if (a[i] < b[j]) {
            arr[i] = j;
            cnt++;
            j++;
        }
    }
    if (cnt < n - x) {
        cout << "NO\n";
        return;
    }
    if (cnt == n - x) {
        for (int el : arr) {
            if (el != -1) cout << el << '\n';
            else break;
        }
        for (int i = )
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; 
    while(t--) solve();
    return 0;
}