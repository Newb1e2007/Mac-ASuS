#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    if ((n + 1) / 2 % 2 == 1) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    if (n % 2 == 1) {
        cout << n / 2 << '\n';
        int x = (n + 1) / 2;
        for (int i = 1; i <= n; i+=2) {
            if (i != x - 1) {
                cout << i << ' ';
            }
        }
        cout << '\n' << n / 2 + 1 << '\n';
        cout << x - 1 << ' ';
        for (int i = 2; i < n; i+=2) {
            cout << i << ' ';
        }
    } else {
        cout << n / 2 << '\n';
        for (int i = 1; i < n / 2; i+=2) {
            cout << i << ' ' << n - i + 1 << ' '; 
        }
        cout << '\n' << n / 2 << '\n';
        for (int  i = 2; i <= n / 2; i+=2) {
            cout << i << ' ' << n - i + 1 << ' ';
        }
    }

    return 0;
}