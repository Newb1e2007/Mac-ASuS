#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll binpow(ll a, int n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res *= a;
        }
        a *= a;
        n >>= 1;
    }
    return res;
}

/*void solve() {
    int n, m; cin >> n >> m;
    if (m > n) {
        cout << 1 << '\n';
        return;
    }
}*/

int sumOfDiv(int n) {
    int answ = 1;
    int i = 2, j = n;
    //int st = sqrt(j);
    while (i <= sqrt(j)) {
        if ((j % i)) {
            int summ = 1;
            int m = 1;
            while (j % i) {
                j /= i;
                m *= i;
                summ += m;
            }
            answ *= summ;
        }
        i++;
    }
    if (j > 1) answ *= j + 1;
    return answ;
}

/*
def sum_of_divisors(n):
    s = 1
    i = 2
    j = n
    j_sqrt = math.isqrt(j)
    while i <= j_sqrt:
        if j % i == 0:
            f = 1
            m = 1
            while j % i == 0:
                j //= i
                m *= i
                f += m
            j_sqrt = math.isqrt(j)
            s *= f
        i += 1
    if j > 1:
        s *= j + 1
    return s


def sum_of_proper_divisors(n):
    return sum_of_divisors(n) - n
*/

void solve() {
    int n; cin >> n;
    map<int, int> el_cnt;
    for (int i = 1; i <= n; i++) {
        int a = sumOfDiv(i);
        int b = sumOfDiv(a);
        if (b == i && a != b && el_cnt[a] == 0 && el_cnt[b] == 0) {
            el_cnt[a] = 1;
            el_cnt[b] = 1;
            cout << a << ' ' << b << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;// cin >> t;
    while(t--) solve();
    return 0;
}
