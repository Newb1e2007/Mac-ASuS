#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<bool> cnt(n);
    for (int i = 0; i < n - 1; i++) {
        int newN; cin >> newN;
        cnt[newN - 1] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (!cnt[i]) {
            cout << i + 1;
            return 0;
        }
    }
}