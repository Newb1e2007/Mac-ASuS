#include <bits/stdc++.h>

using namespace std;
using ui = unsigned int;

ui cur = 0;

unsigned int nextRand(ui a, ui b) {
    cur = cur * a + b; // вычисляется с переполнениями
    return cur >> 8; // число от 0 до 2^{24}-1
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 1<<24;
    int m, q; cin >> m >> q;
    ui a, b; cin >> a >> b;
    int pref[n + 1];
    pref[0] = 0;
    for (int i = 0; i < m; i++) {
        ui add = nextRand(a, b);
        ui l = nextRand(a, b);
        ui r = nextRand(a, b);
        if (l > r) swap(l, r);
        pref[l + 1] = add;
        pref[r + 1] = -add;
    }
    ui arr[n];
    for (int i = 1; i < n; i++) {
        arr[i - 1] = pref[i] + pref[i - 1];
    }
    unsigned long long summ = 0;
    for (int i = 0; i < q; i++) {
        ui l = nextRand(a, b);
        ui r = nextRand(a, b);
        if (l > r) swap(l, r);
        for (ui j = l; j <= r; j++) {
            summ += arr[j];
            summ %= 1<<32;
        }
    }
    cout << summ;
    return 0;
}