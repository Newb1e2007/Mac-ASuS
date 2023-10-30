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
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    map<int, int> allVar;
    int l = 0;
    for (int i = 0; i < n / nod(n, k); i++) {
        allVar[l]++;
        l = (l + k)%n;
    }
    vector<int> answ(m + 1);
    /*for (auto pos : allVar) {
        cout << pos.first << ' ' << pos.second << '\n';
    }
    return 0;*/
    for (auto pos : allVar) {
        int curL = pos.first;
        vector<bool> curCnt(m + 1);
        for (int i = 0; i < k; i++) {
            if (!curCnt[arr[curL]]) {
                answ[arr[curL]] += pos.second;
                curCnt[arr[curL]] = true;
            }
            curL = ++curL%n;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << answ[i] << ' ';
    }
    return 0;
}