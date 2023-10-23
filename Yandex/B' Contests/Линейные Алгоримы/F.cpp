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
    int m, q; cin >> m >> q;
    ui a, b; cin >> a >> b;
    vector<int> cnt(n);
    for (int i = 0; i < m; i++) {
        ui add = nextRand(a, b);
        ui l = nextRand(a, b);
        ui r = nextRand(a, b);
        if (l > r) swap(l, r);
        cnt[l - 1] += (int)add;
        cnt[r - 1] -= (int)add;
        //cout << pref[r] << '\n';
    }
    //vector<ui> arr(n);
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + cnt[i - 1];
    }
    
    ull summ = 0;
    ull mod = (ull)1<<(ull)32;
    for (int i = 0; i < q; i++) {
        ui l = nextRand(a, b);
        ui r = nextRand(a, b);
        if (l > r) swap(l, r);
        for (ui j = l; j <= r; j++) {
            summ += (ull)pref[j];
        }
        summ %= mod;
    }
    cout << summ;
    return 0;
}