#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int cnt = 0;
    for (int i = 2; i * i <= n; i++) {
        if (i * i == n) {
            cnt++;
        } else {
            cnt += 2;
        }
    }
    cout << cnt;
}