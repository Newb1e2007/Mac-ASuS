#include <bits/stdc++.h>
#define ull unsigned long long
#define ld long double

using namespace std;

bool check(ld a, ull k, ld b, ull m, ull x, ull mid) {
    ull w1 = mid - mid/k;
    ull w2 = mid - mid/m;
    ld w11 = w1, w21 = w2, xld = x;
    return a * w11 + b * w21 >= xld;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ull k, m, x;
    ld a, b;
    cin >> a >> k >> b >> m >> x;

    ull l = 0, r = 2 * x, mid; 
    while (r - l > 1) {
        mid = l + (r - l) / 2;
        if (check(a, k, b, m, x, mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r;
    return 0;
} 