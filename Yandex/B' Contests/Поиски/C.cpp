#include <bits/stdc++.h>
#define ld long double

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(20);
    ld c;
    cin >> c;
    ld i = 0.0, j = c, mid, minDiff = 1e-6;
    while (j - i > minDiff) {
        mid = (i + j) / 2;
        if (mid * mid + sqrt(mid) == c) {
            cout << mid;
            return 0;
        }
        if (mid * mid + sqrt(mid) < c) {
            i = mid;
        } else {
            j = mid;
        }
    }
    cout << (i + j)/2;
    return 0;
}