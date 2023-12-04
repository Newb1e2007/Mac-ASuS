#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

bool check(vector<int>& arr, int x) {
    int cnt = 0;
    for (int el : arr) {
        if (el > x) cnt += el - x;
        if (cnt > x) break;
    }
    if (cnt > x) return false;
    else return true;
}

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    int summ = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        summ += arr[i];
    }
    sort(arr.rbegin(), arr.rend());  
    int l = 0, r = arr[0] + 1;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (check(arr, mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}