#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> &arr, int dist, int cowsCount) {
    int cows = 1, lastStall = arr[0];
    for (int currentStall : arr) {
        if (currentStall - lastStall < dist) {
            continue;
        } else {
            cows++;
            lastStall = currentStall;
        }
    }
    return cows >= cowsCount;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> stalls(n);
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }
    sort(stalls.begin(), stalls.end());
    int i = 0, j = stalls.back() - stalls[0] + 1;
    while (i + 1 < j) {
        int mid = (i + j)/2;
        if (check(stalls, mid, k)) {
            i = mid;
        } else {
            j = mid;
        }
    }
    cout << i;
    return 0;
}