#include <bits/stdc++.h>

using namespace std;
using ui = unsigned int;
using ull = unsigned long long;

ui cur = 0;

unsigned int nextRand(ui a, ui b) {
    cur = cur * a + b; // вычисляется с переполнениями
    return cur >> 8; // число от 0 до 2^{24}-1
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 1<<24;
    vector<int> arr(n);
    int m, q; cin >> m >> q;
    unsigned int a, b; cin >> a >> b;
    for (int i = 0; i < m; i++) {
        unsigned int add = nextRand(a, b);
        unsigned int l = nextRand(a, b);
        unsigned int r = nextRand(a, b);
        if (l > r) swap(l, r);
        for (ui j = l - 1; j < r; j++) {
            arr[j] += (int)add;
        }
    }
    ull summ = 0;
    for (int i = 0; i < q; i++) {
        unsigned int l = nextRand(a, b);
        unsigned int r = nextRand(a, b);
        if (l > r) swap(l, r);
        for (ui j = l - 1; j < r; j++) {
            
            summ += (ull)arr[j];
        }
    }
    ull mod = (ull)1 << (ull)32;
    cout << summ % mod << '\n';
    summ %= mod;
    cout << summ;
    return 0;
}