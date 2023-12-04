#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n; cin >> n;
    int a, b, c, d; cin >> a >> b >> c >> d;
    int answ = 1e9;
    for (int i = 0; (i - 1) * a <= n; i++) {
        //cout << i << ": ";
        //cout << i * b + max((n - i * a), 0) / c * d + min(max((n - i * a), 0) % c, d) << '\n';
        answ = min(answ, i * b + max((n - i * a), 0) / c * d + min(max((n - i * a), 0) % c, d));
    }
    cout << answ;
    //cout << min(min(min(min((n / a) * b + ((n % a) + c - 1) / c * d, (n / a) * b + ((n % a)) / c * d + (n%a)%c), min((n / c) * d + ((n % c) + a - 1) / a * b, (n / c) * d + (n % c) / a *  b + (n % c) % a)), min((n + a - 1)/a *b, (n + c - 1) / c * d)), min((n / a) * b  + n % a, (n / c) * d + n % c));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}