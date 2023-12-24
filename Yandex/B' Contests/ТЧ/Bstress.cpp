#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int ITER_COUNT = 1e5;
const int INF = -INT32_MAX;

struct Test {
    int a, b, c;
};

Test gen_test() {
    uniform_int_distribution<int> n_dist(1, 1e4);
    Test nt;
    nt.a = n_dist(rng);
    nt.b = n_dist(rng);
    nt.c = n_dist(rng);
    return nt;
}

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

pii solve_smart(Test nt) {
    int a = nt.a, b = nt.b, c = nt.c;
    int d = gcd(a, b);
    if (c % d != 0) {
        pii ret; ret.first = INF; ret.second = INF;
        return ret;
    } 
    auto [x, y] = smart_gcd(a / d, b / d);
    x *= c / d;
    y *= c / d;
    while (x >= b) {
        x -= b; 
        y += a;
    }
    while (x < 0) {
        x += b;
        y -= a;
    }
    return {x, y};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("output.txt", "w", stdout);
    for (int i = 0; i < ITER_COUNT; i++) {
        Test nt = gen_test();
        if (nt.c % gcd(nt.a, nt.b) != 0) {
            continue;
        }
        pii answ = solve_smart(nt);
        if (answ.first * nt.a + answ.second * nt.b == nt.c) {
            cout << "TEST " << i + 1 << " PASSED\n";
        } else {
            cout << "TEST " << i + 1 << " FAILED\n";
            cout << nt.a << ' ' << nt.b << ' ' << nt.c << '\n';
            return 0;
        }
    }
    cout << "AC\n";
}