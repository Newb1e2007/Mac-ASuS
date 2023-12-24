#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

pii smart_gcd(int a, int b) {
    if (a == 1 && b == 0) {
        return {1, 0};
    }
    pii xy = smart_gcd(b, a % b);
    return {xy.second, xy.first - xy.second * (a / b)};
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c; cin >> a >> b >> c;
    int d = gcd(a, b);
    if (c % d != 0) {
        cout << "Impossible";
        return 0;
    } 
    auto [x, y] = smart_gcd(a / d, b / d);
    x *= c / d;
    y *= c / d;
    while (x >= b / d) {
        x -= b / d; 
        y += a / d;
    }
    while (x < 0) {
        x += b / d;
        y -= a / d;
    }
    cout << x << ' ' << y;
}