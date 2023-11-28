#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> a(n), b(m), c(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        c[i] = b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int answ = 0, indR = 0, indL = 0;
    map<int, int> aboba;
    while (indR < m) {
        while (indL < n && a[indL] <= b[indR]) {
            answ++;
            indL++;
        }
        aboba[b[indR]] = answ;
        indR++;
    }
    for (int i : c) {
        cout << aboba[i] << ' ';
    }
    return 0;
}