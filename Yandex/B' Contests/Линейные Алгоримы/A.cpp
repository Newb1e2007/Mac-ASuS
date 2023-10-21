#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct op
{
    int l;
    int r;
    ll d;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {cin >> arr[i];}
    vector<op> ops(m);
    for (int i = 0; i < m; i++) {cin >> ops[i].l >> ops[i].r >> ops[i].d;}
    vector<int> op_cnt(m); 
    for (int i = 0; i < k; i++) {
        int l, r; cin >> l >> r;
        op_cnt[l - 1]++; op_cnt[r]--;

    }
    vector<int> op_prev(m + 1);
    for (int i = 1; i <= m; i++) {
        op_prev[i] = op_prev[i - 1] + op_cnt[i - 1];
    }
    vector<ll> arrZeros(n);
    for (int i = 0; i < m; i++) {
        arrZeros[ops[i].l - 1] += ops[i].d*op_prev[i + 1];
        arrZeros[ops[i].r] -= ops[i].d*op_prev[i + 1];
    }
    vector<ll> prev(n + 1); 
    for (int i = 1; i <= n; i++) {
        prev[i] = prev[i - 1] + arrZeros[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        cout << prev[i] + arr[i - 1] << ' ';
    }
    return 0;
} 