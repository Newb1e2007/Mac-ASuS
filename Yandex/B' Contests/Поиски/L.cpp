#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;
    //arr[0] = 1;
    //arr[n - 1] = 0;
    long long l = 0, r = n - 1, mid, midEl;
    while (r - l > 1) {
        mid = l + (r - l) / 2;
        cout << "? " << mid + 1 << endl;
        fflush(stdout);
        cin >> midEl;
        if (midEl == 0) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << "! " << l + 1 << endl;
    fflush(stdout);
    return 0;
}