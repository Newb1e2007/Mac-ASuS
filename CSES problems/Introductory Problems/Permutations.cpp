#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    if (n < 4 && n > 1) {
        cout << "NO SOLUTION";
        return 0;
    }
    for (int i = 2; i <= n; i+=2) {
        cout << i << ' ';
    }
    for (int i = 1; i <= n; i+=2) {
        cout << i << ' ';
    }
    return 0;
}