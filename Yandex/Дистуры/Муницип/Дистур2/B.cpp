#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

/*void solve() {
    int n; cin >> n;
    string s = to_string(n);
    int first = 0;
    int second = 0;
    if (s.length() == 3) {
        first = n / 10;
        second = n % 10;
    } else if (s.length() == 2) {
        first = n / 10;
        second = n % 10;
    } else {
        first = n / 100;
        second = n % 100;
    }
    //cout << first << ' ' << second << '\n';
    if ((first > second && second != 0) || first == 0) swap(first, second);
    int a, b, c, d;
    if (first <= 10) {
        a = 1;
        b = first - 1;
    } else {
        a = first - 9;
        b = first - a;
    }
    if (second == 0) {
        c = 0;
        d = 0;
        cout << a * 1000 + b * 100 + c * 10 + d;
        return;
    }
    if (second <= 10) {
        c = 1;
        d = second - 1;
    } else {
        c = second - 9;
        d = second - c;
    }
    cout << a * 1000 + b * 100 + c * 10 + d;
}*/

void solve() {
    int n; cin >> n;
    string s = to_string(n);
    int first = 0;
    int second = 0;
    int a, b ,c , d;
    if (s.length() == 2) {
        if (n / 10 < n % 10) {cout << 0; return;}
    }
    if (s.length() == 3) {
        if (n / 10 > 18) {cout << 0; return;}
    }
    if (s.length() == 4) {
        if (n / 100 > 18 || n % 100 > 18 || n % 100 / 10 == 0) {cout << 0; return;}
    }

    if (s.length() == 3) {
        first = n / 10; 
        second = n % 10;
        if (second != 0) swap(first, second);
        if (first > 10) {
            a = first - 9;
            b = 9;
        } else {
            a = 1;
            b = first - 1;
        }
        if (second >= 10) {
            c = second - 9;
            d = 9;
        } else {
            c = 0;
            d = second;
        }
    } else if (s.length() == 2) {
        first = n / 10;
        second = n % 10;
        if ((first > second && second != 0) || first == 0) swap(first, second);
        a = 1;
        b = first - 1;
        c = 0;
        d = second;
    } else {
        first = n / 100;
        second = n % 100;
        if ((first > second && second != 0) || first == 0) swap(first, second);
        if (first > 10) {
            a = first - 9;
            b = 9;
        } else {
            a = 1;
            b = first - 1;
        }
        if (second >= 10) {
            c = second - 9;
            d = 9;
        } else {
            c = 0;
            d = second;
        }
    }
    cout << a * 1000 + b * 100 + c * 10 + d;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}