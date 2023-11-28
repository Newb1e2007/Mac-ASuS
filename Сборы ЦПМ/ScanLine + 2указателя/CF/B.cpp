#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, d; cin >> n >> d;
    vector<int> arr(n);
    int plus  = 0;
    cin >> arr[0];
    if (arr[0] < 0) {
        plus = abs(arr[0]);
        arr[0] = 0;
    }
    for (int i = 1; i < n; i++) {
        cin >> arr[i];
        arr[i] += plus;
    }
    int l = 0, r = 0, summ = 0, cnt = 0, prev = arr[0];
    while (r < n) {
        if (summ <= d) {
            cnt++;
            r++;
            summ += arr[r] - prev;
            prev = arr[r];
        } else {
            summ -= arr[l + 1] - arr[l];
            cnt += 
            l++;
        }
    }
    cout << cnt;
    return 0;
}