#include <bits/stdc++.h>

using namespace std;

pair<int, int> check(vector<int> &arr1, int hight, int n) {
    int diffCount = 0, sameCount = 0;
    int maxFp = 0, currentInd = 0;
    int l = -1, r = n;
    while(r - l > 1) {
        int mid = l + (r - l) / 2;
        if (arr1[mid] == hight) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (arr1[r] != hight) return {0, currentInd};
    sameCount++;
    for (int i = r + 1; i < n; i++) {
        if (arr1[i] != hight) diffCount++;
    }
    if (maxFp < diffCount*sameCount) {
        currentInd = r + 1;
        maxFp = diffCount*sameCount;
    }
    while (true) {
        l = r;
        r = n;
        while(r - l > 1) {
            int mid = l + (r - l) / 2;
            if (arr1[mid] == hight) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (arr1[r] != hight) return {maxFp, currentInd};
        sameCount++;
        for (int i = currentInd; i < r; i++) {
            if (arr1[i] != hight) diffCount--;
        }
        if (maxFp < diffCount*sameCount) {
            currentInd = r + 1;
            maxFp = diffCount*sameCount;
        }
    }
    return {maxFp, currentInd};
}

int main() {
    /*ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/

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
        pair<int, int> result = check(arr1, hight, n);
        cout << result.first << " " << result.second << "\n";
    }
    return 0;
}