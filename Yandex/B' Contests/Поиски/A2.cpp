#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> a(n), fP(100001), prev(100001), l(100001), r(100001), cntA(100001);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cntA[a[i]]++;
    }
    int ind = 0;
    for (int cnt : cntA) {
        r[ind++] = n - cnt;
    }
    vector<int> ts(m);
    for (int i = 0; i < m; i++) {
        cin >> ts[i];
    }

    int pos = 0;
    for (int ai : a) {
        l[ai]++;
        r[ai] -= pos - prev[ai];
        pos++;
        prev[ai] = pos;
        fP[ai] = max(fP[ai], l[ai]*r[ai]);
    }
    for (int p : ts) {
        cout << fP[p] << ' ';
    }

    return 0;
}