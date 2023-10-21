#include <bits/stdc++.h>

using namespace std;

int countTargets(vector <int> &arr, int target, int l, int r) {
    int r1 = r, r2 = r, l1 = l, l2 = l;
    while (r1 - l1 > 1) {
        int mid = l1 + (r1 - l1) / 2;
        if (arr[mid] >= target) {
            r1 = mid;
        } else {
            l1 = mid;
        }
    }
    while (r2 - l2 > 1) {
        int mid = l2 + (r2 - l2) / 2;
        if (arr[mid] > target) {
            r2 = mid;
        } else {
            l2 = mid;
        }
    }
    return r2 - r1;
}

int fP(vector<int> &arr, int target, int i, int n) {
    vector<int> arr1 = arr;
    sort(arr1.begin(), arr1.begin() + i);
    int sameCount = countTargets(arr1, target, -1, i);
    sort(arr1.begin() + i, arr1.end());
    int diffCount = n - i - countTargets(arr1, target, i - 1, n);
    //cout << target << ' ' << i << ' ' << sameCount*diffCount << '\n';
    return sameCount*diffCount;
}

int solve(vector<int> &arr1, int l, int r, int n, int hight) {
    while (r - l > 2) {
        int lm = l + (r - l)/3, rm = l + (r - l)/3*2;
        int lmF = fP(arr1, hight, lm, n);
        int rmF = fP(arr1, hight, rm, n);
        if (lmF == rmF && lmF == 0) {
            return max(solve(arr1, lmF + 1, rmF, n, hight), max(solve(arr1, l, lmF, n, hight), solve(arr1, rmF + 1, r, n, hight)));
        }
        if (lmF >= rmF) {
            r = rm;
        }
        if (lmF <= rmF) {
            l = lm;
        }
    }
    return max(fP(arr1, hight, l, n), max(fP(arr1, hight, l + 1, n), fP(arr1, hight, r, n)));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n), arr2(m);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }
    for (int hight : arr2) {
        int l = 1, r = n - 1;
        /*while (fP(arr1, hight, l, n) == 0) {
            l++;
        } 
        while (fP(arr1, hight, r, n) == 0) {
            r--;
        }*/
        
        /*while (r - l > 2) {
            int lm = l + (r - l)/3, rm = l + (r - l)/3*2;
            int lmF = fP(arr1, hight, lm, n);
            int rmF = fP(arr1, hight, rm, n);
            if (lmF >= rmF) {
                r = rm;
            }
            if (lmF <= rmF) {
                l = lm;
            }
        }*/
        //cout << max(fP(arr1, hight, l, n), max(fP(arr1, hight, l + 1, n), fP(arr1, hight, r, n))) << ' ';
        cout << solve(arr1, l, r, n, hight) << ' ';
    }
    return 0;
}