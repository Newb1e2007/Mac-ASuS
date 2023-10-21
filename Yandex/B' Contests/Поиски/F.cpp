#include <bits/stdc++.h>

using namespace std;

int binSearch(vector<int> &arr1, vector<int> &arr2, int n) {
    int l = 0, r = n - 1, mid;
    while (r - l > 1) {
        mid = l + (r - l) / 2;
        if (arr1[mid] == arr2[mid]) {
            return mid;
        } else if (arr1[mid] > arr2[mid]) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (max(arr1[l], arr2[l]) > max(arr1[r], arr2[r])) {
        return r;
    } else {
        return l;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, l, q;
    cin >> n >> m >> l;
    vector<vector<int> > arrs1(n, vector<int> (l));
    vector<vector<int> > arrs2(m, vector<int> (l));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            cin >> arrs1[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < l; j++) {
            cin >> arrs2[i][j];
        }
    }
    cin >> q;
    vector<pair<int, int>> allQ(q);
    for (int i = 0; i < q; i++) {
        cin >> allQ[i].first >> allQ[i].second;
    }
    for (pair<int, int> q : allQ) {
        cout << binSearch(arrs1[q.first - 1], arrs2[q.second - 1], l) + 1 << "\n";
    }
    return 0;
}