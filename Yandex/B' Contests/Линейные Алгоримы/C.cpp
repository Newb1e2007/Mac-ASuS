#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, count = 0; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {cin >> arr[i]; if (arr[i] < 0) count++;}
    if (count == n) {
        int minElInd = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[minElInd]) {
                minElInd = i;
            }
        }
        cout << minElInd + 1 << ' ' << minElInd + 1 << ' ' << arr[minElInd];
        return 0;
    }
    vector<int> pref(n + 1);
    for (int i = 1; i < n + 1; i++) {
        pref[i] = pref[i - 1] + arr[i - 1];
    }

    int minElInd = 0, maxDiff = pref[minElInd], resL = 1, resR = 1;
    for (int i = 1; i < n + 1; i++) {
        if (pref[i] - pref[minElInd] > maxDiff) {
            maxDiff = pref[i] - pref[minElInd];
            resL = minElInd + 1; resR = i;
        }
        if (pref[i] < pref[minElInd]) {
            minElInd = i;
        }
    }
    cout << resL << ' ' << resR << ' ' << maxDiff;
    return 0;
}