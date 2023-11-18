#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // -------
    int summ = arr[0];
    int answ = arr[0];
    bool lastCh = arr[0] % 2;
    int i = 1;
    if (answ < 0) {
        while (i < n && arr[i] < 0) {
            answ = max(answ, arr[i]);
            i++;
        }
    }
    if (i > n - 1) {
        cout << answ << "\n";
        return;
    }
    if (summ < 0) summ = 0;
    for (int j = i; j < n; j++) {
        cout << arr[j] << ' ' << answ << " before\n";
        if (arr[j] % 2 == lastCh) {
            answ = max(answ, summ);
            summ = arr[j];
            answ = max(answ, summ);
        } else {
            if (arr[j] >= 0) {
                summ += arr[j];
                answ = max(answ, summ);
                lastCh = arr[j] % 2;
            } else {
                summ += arr[j];
                if (summ < 0) {
                    summ = 0;
                }
                lastCh = arr[j] % 2;
            }
        }
        cout << summ << ' ' << answ << " after\n";
    }
    cout << answ << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}