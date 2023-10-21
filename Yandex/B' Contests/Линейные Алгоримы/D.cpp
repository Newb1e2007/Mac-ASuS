#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int x; cin >> x;
    ull i = 1, j = 1, cx = 1;

    for (int k = 0; k < x; k++) {
        if (i*i < j*j*j) {
            cx = i*i;
            i++;
        } else if (i*i > j*j*j) {
            cx = j*j*j;
            j++;
        } else {
            cx = i*i;
            i++; j++;
        }
    }
    cout << cx;
}