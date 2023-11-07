#include <bits/stdc++.h>

using namespace std;

int nod(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    if (b) {
        return nod(b, a%b);
    } else {
        return a;
    }
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int reps = n / nod(n, k) * k / k;
    int l = 0;
    vector<int> M_cnt(m + 1);
    //map<int, bool> curCnt;
    for (int i = 0; i < reps; i++) {
        vector<bool> curCnt(m + 1);
        for (int j = 0; j < k; j++) {
            if (!curCnt[arr[l]]) {
                curCnt[arr[l]] = 1;
                M_cnt[arr[l]]++;
            }
            l++;
            l %= n;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << M_cnt[i] << ' ';
    }
    return 0;
}