#include <bits/stdc++.h>

using namespace std;

bool is_prime(int a) {
    if (a == 1) return false;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int x = n / 2;
    int y = n - x;
    while (true) {
        if (is_prime(x) && is_prime(y)) {
            cout << x << ' ' << y;
            return 0;
        }
        y++;
        x--;
    }
}