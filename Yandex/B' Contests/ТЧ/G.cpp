#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d; cin >> a >> b >> c >> d;
    cout << a * d + c * b / gcd(a * d + c * b, b * d) << ' ' << b * d / gcd(a * d + c * b, b * d);
}