#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
__int128_t MOD = 1e9 + 7;

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
    return answ;
}

void solve() {
    //cerr << ".....\n";
    int n, m, k; cin >> n >> m >> k;
    //cerr << "emm\n";
    ll a = 0, b = 0, c = 0;
    //cerr << "nexui\n";
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
    //cout << "xui\n";
    if (m == 0 && k == 0) {
        cout << 1;
        return;
    }
    __int128_t g = 1;
    __int128_t h = 0;
    for (int i = 0; i < m; i++) {
        g *= 10;
    }
    __int128_t cur = 1;
    for (int i = 0; i < k; i++) {
        cur *= 10;
    }
    h = b * cur + c - b;
    if (k == 0) h = b;
    if (cur > 1) cur--;
    g *= cur;
    //__int128_t h = b * cur + c * cur2;
    set<__int128_t> arr = simplification(g, h);
    __int128_t res = 1;
    for (auto el : arr) res *= el;
    res %= MOD;
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
