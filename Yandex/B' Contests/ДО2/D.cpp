#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MAXN = 1e6;
vector<ll> st(MAXN * 4);
vector<ll> p1(MAXN * 4);
vector<ll> p2(MAXN * 4, -1);

void build(int v, int l, int r) {
    if (r - l == 1) {
        st[v] = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid, r);
    st[v] = 0;
}

void add_apply(int v, int l, int r, ll x) {
    st[v] += x * (r - l);
    p1[v] += x; 
    //cout << v << ' ' << st[v] << '\n';
}

void set_apply(int v, int l, int r, ll x) {
    st[v] = x * (r - l);
    p1[v] = 0;
    p2[v] = x;
    //cout << v << ' ' << st[v] << '\n';
}

void push(int v, int l, int r) {
    ll ass_push = p2[v];
    p2[v] = -1;
    ll x = p1[v];
    p1[v] = 0;
    int mid = (r + l) / 2;

    if (ass_push != -1) {
        set_apply(2 * v + 1, l, mid, ass_push);
        set_apply(2 * v + 2, mid, r, ass_push);
    }
    if (x != 0) {
        add_apply(2 * v + 1, l, mid, x);
        add_apply(2 * v + 2, mid, r, x);
    }
}

void add(int ql, int qr, ll x, int v, int l, int r) {
    if (qr <= l || r <= ql) {
        return;
    } 
    if (ql <= l && r <= qr) {
        return add_apply(v, l, r, x);
    }
    int mid = (r + l) /  2;
    push(v, l, r);
    add(ql, qr, x, 2 * v + 1, l, mid);
    add(ql, qr, x, 2 * v + 2, mid, r);
    st[v] = st[2 * v + 1] + st[2 * v + 2];
} 

void _set(int ql, int qr, ll x, int v, int l, int r) {
    if (qr <= l || r <= ql) {
        return;
    } 
    if (ql <= l && r <= qr) {
        return set_apply(v, l, r, x);
    }
    int mid = (r + l) /  2;
    push(v, l, r);
    _set(ql, qr, x, 2 * v + 1, l, mid);
    _set(ql, qr, x, 2 * v + 2, mid, r);
    st[v] = st[2 * v + 1] + st[2 * v + 2];
}

ll get(int ql, int qr, int v, int l, int r) {
    if (qr <= l || r <= ql) {
        return 0;
    }
    if (ql <= l && r <= qr) {
        return st[v];
    }
    int mid = (r + l) / 2;
    push(v, l, r);
    return get(ql, qr, 2 * v + 1, l, mid) + get(ql, qr, 2 * v + 2, mid, r);    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    build(0, 0, n);
    for (int i = 0; i < m; i++) {
        int t; cin >> t;
        if (t == 2) {
            int l, r; ll v; cin >> l >> r >> v;
            add(l, r, v, 0, 0, n);
        } else if (t == 1) {
            int l, r; ll v; cin >> l >> r >> v;
            _set(l, r, v, 0, 0, n);
        } else {
            int l, r; cin >> l >> r;
            cout << get(l, r, 0, 0, n) << '\n';
        }
    }
    return 0;
}
