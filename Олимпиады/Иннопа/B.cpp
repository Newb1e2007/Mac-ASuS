#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

__int128_t gcd(__int128_t a, __int128_t b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

set<__int128_t> simplification(__int128_t a, __int128_t b) {
    a /= gcd(max(a, b), min(b, a));
    set<__int128_t> answ;
    __int128_t d = 2;
    while (a > 1) {
        while (a % d == 0) {
            answ.insert(d);
            a /= d;
        }
        d++;
    }
    //reverse(answ.begin(), answ.end());
    return answ;
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int a = 0, b = 0, c = 0;
    if (n != 0) 
        cin >> a;
    else 
        {string s1; getline(cin, s1);}
    if (m != 0) 
        cin >> b;
    else 
        {string s2; getline(cin, s2);}
    if (k != 0) 
        cin >> c;
    else 
        {string s3; getline(cin, s3);}

    /*__int128_t x = 1;
    for (int i = 0; i < m; i++) {
        x *= 10;
    }
    __int128_t y = 0;
    for (int i = 0; i < k; i++) {
        y *= 10;
        y += 9;
    }
    if (y == 0) y = 1;
    __int128_t g = x * y;
    __int128_t h = a * x * y + b * y + c * x;

    g /= gcd(g, h);

    set<__int128_t> arr;
    for (__int128_t i = 2; i * i <= g; i++) {
        if (g % i == 0) {
            arr.insert(i);
            if (i * i != g) {
                arr.insert(g / i);
            }
        }
    }
    __int128_t res = 1;
    for (auto el : arr) res *= el;
    vector<int> ch;
    while (res != 0) {
        ch.push_back(res % 10);
        res /= 10; 
    }
    reverse(ch.begin(), ch.end());
    for (auto el : ch) cout << el;*/
    set<__int128_t> arr;
    if (m == 0 && k == 0) {
        cout << 1;
        return;
    } else if (k == 0) {
        __int128_t h = b;
        __int128_t g =1;
        for (int i = 0; i < m; i++) {
            g *= 10;
        }
        h += a * g;
        arr = simplification(g, h);
    } else if (m == 0) {
        __int128_t g = 1;
        for (int i = 0; i < k; i++) {
            g *= 10;
        }
        g--;
        __int128_t h = a * g + c;
        arr = simplification(g, h);
    } else {
        __int128_t y = a;
        __int128_t x = b;
        for (int i = 0; i < k; i++) {
            x *= 10;
        }
        x += c;
        __int128_t z = b;
        __int128_t g = 1;
        __int128_t h = y * g + x - z;

        for (int i = 0; i < k; i++) {
            g *= 10;
        }
        g--;
        for (int i = 0; i < m; i++) {
            g *= 10;
        }
        arr = simplification(g, h);
    }
    __int128_t res = 1;
    //cout << arr.size() << '\n';
    for (auto el : arr) res *= el;
    vector<int> ch;
    while (res != 0) {
        ch.push_back(res % 10);
        res /= 10;
    }
    reverse(ch.begin(), ch.end());
    for (auto el : ch) cout << el;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while(t--) solve();

    return 0;
}
