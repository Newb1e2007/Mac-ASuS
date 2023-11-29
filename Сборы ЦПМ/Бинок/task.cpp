#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

bool check(vector<int>& arr, int n, int mid) {
    if (arr[n - 1] < mid) {
        return false;
    }
    int bag1 = (arr[n - 1] - mid) / 3;
    int bag2 = bag1 * 2;
    int ind = n - 2;
    while (ind >= 2) {
        if (arr[ind] < mid) {
            if (bag1 < mid - arr[ind]) {
                return false;
            } else {
                bag1 -= mid - arr[ind];
                bag1 = bag2 + bag1 / 3;
                bag2 = bag1 / 3 * 2;
            }
        } else {
            int tmp = arr[ind] - mid + bag1;
            bag1 = bag2 + tmp / 3;
            bag2 = tmp / 3 * 2;
        }
        ind--;
    }
    if ((arr[1] < mid && bag1 < mid - arr[1]) || (arr[0] < mid && bag2 < mid - arr[0])) return false; 
    return true;
}

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    int maxN = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxN = max(maxN, arr[i]);
    }
    int l = 0, r = maxN + 1;
    while (r - l > 1) {
        int mid = l + (r - l) / 2;
        if (check(arr, n, mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}