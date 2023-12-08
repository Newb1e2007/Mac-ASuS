#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e5;
vector<ll> st(MAXN * 4);
vector<ll> sp(MAXN * 4);
vector<ll> arr;

void apply(ll x, int v, int l, int r) {
    sp[v] += x;
    st[v] += x;
}

void push(int v, int l, int r) {
    int x = sp[v];
    if (x == 0) return;
    sp[v] = 0;
    int mid = l + (r - l) / 2;
    apply(x, 2 * v + 1, l, mid);
    apply(x, 2 * v + 2, mid, r);
}

void build(int v, int l, int r) {
    if (r - l == 1) {
        st[v] = arr[l];
        return;
    }
    int mid = l + (r - l) / 2;
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid, r);
    st[v] = max(st[2 * v + 1], st[2 * v + 2]);
}

void update(int ql, int qr, ll x, int v, int l, int r) {
    if (qr <= l || r <= ql) {
        return;
    }
    if (ql <= l && r <= qr) {
        return apply(x, v, l, r);
    }
    int mid = l + (r - l) / 2;
    push(v, l, r);
    update(ql, qr, x, 2 * v + 1, l, mid);
    update(ql, qr, x, 2 * v + 2, mid, r);
    st[v] = max(st[2 * v + 1], st[2 * v + 2]);
}

ll get(int ql, int qr, int v, int l, int r) {
    if (qr <= l || r <= ql) {
        return 0;
    }
    if (ql <= l && r <= qr) {
        return st[v];
    }
    int mid = l + (r - l) / 2;
    push(v, l, r);
    return max(get(ql, qr, 2 * v + 1, l, mid), get(ql, qr, 2 * v + 2, mid, r));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build(0, 0, n);
    int m; cin >> m;
    for (int i = 0; i < m ;i++) {
        char c; cin >> c;
        if (c == 'm') {
            int l, r; cin >> l >> r;
            cout << get(l - 1, r, 0, 0, n) << ' ';
        } else {
            int l, r; cin >> l >> r;
            ll add; cin >> add;
            update(l - 1, r, add, 0, 0, n);
        }
    }

    return 0;
}