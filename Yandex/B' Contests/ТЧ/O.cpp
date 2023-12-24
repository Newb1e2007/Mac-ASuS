#include <bits/stdc++.h>

using namespace std;

void next_perm(vector<int> &arr, int k, int n) {
    for (int i = k - 1; i >= 0; i--) {
        if (arr[i] < n - k + i + 1) {
            arr[i]++;
            for (int j = i + 1; j < k; j++) {
                arr[j] = arr[j - 1] + 1;
            }
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> inp(k);
    for (int i = 0; i < k; i++) {
        cin >> inp[i];
    }
    vector<int> arr(k);
    int cnt = 0;
    iota(arr.begin(), arr.end(), 1);
    while (true) {
        if (arr == inp) {
            cout << cnt;
            return 0;
        }
        cnt++;
        next_perm(arr, k, n);
    }
}