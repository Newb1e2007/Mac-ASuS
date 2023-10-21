#include <bits/stdc++.h>

using namespace std;

int doubleSearch(vector<int> &arr, int target) {
    int n  = arr.size();
    int i1 = -1, j1 = n, i2 = -1, j2 = n, mid1, mid2;

    /*while (l <= r) {
        int mid = (l + r) / 2;
        
        if (arr[mid] == target) {
            count++; 
            int l = mid - 1;
            int r = mid + 1;
            while (l >= 0 && arr[l] == target) {
                count++;
                l--;
            }
            while (r < n && arr[r] == target) {
                count++;
                r++;
            }
            return count;

        } else if (arr[mid] > target) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }*/
    while (j1 - i1 > 1) {
        mid1 = (i1 + j1) / 2;
        if (arr[mid1] >= target) {
            j1 = mid1;
        } else {
            i1 = mid1;
        }
    }
    while (j2 - i2 > 1) {
        mid2 = (i2 + j2) / 2;
        if (arr[mid2] > target) {
            j2 = mid2;
        } else {
            i2 = mid2;
        }
    }
    return j2 - j1 ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, count = 0;
    cin >> n;
    vector<int> firstArr(n);
    for (int i = 0; i < n; i++) {
        cin >> firstArr[i];
    }
    sort(firstArr.begin(), firstArr.end());
    cin >> m;
    vector<int> secondArr(m);
    for (int i = 0; i < m; i++) {
        cin >> secondArr[i];
    }

    for (int el : secondArr) {
        count = doubleSearch(firstArr, el);
        cout << count << " ";
    }
    return 0;
}