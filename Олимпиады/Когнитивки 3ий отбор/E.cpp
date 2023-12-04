#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

struct Node {
    int cnt = 0;
};

int MAXN = 5e5;
vector<Node> st(4*MAXN);
vector<int> arr;

Node merge(const Node& l, const Node& r) {
    Node res;
    res.cnt = l.cnt + r.cnt;
    return res;
}

int binpow(int a, int n) {
    int res = 1;
    while (n != 0) {
        if (n & 1)
            res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

void build (int v, int l, int r) {
    if (r - l == 1) {
        Node curV;
        curV.cnt = arr[l];
        st[v] = curV;
        return;
    }
    int mid = l + (r - l) / 2;
    build(2*v + 1, l, mid);
    build(2*v + 2, mid, r);
    st[v] = merge(st[2*v + 1], st[2*v + 2]);
}

void update(int i, int x, int v, int l, int r) {
    if (r - l == 1) {
        Node curV;
        curV.cnt = x;
        st[v] = curV;
        return;
    }
    int mid = l + (r - l) / 2;
    if (i < mid) {
        update(i, x, 2*v + 1, l, mid);
    } else {
        update(i, x, 2*v + 2, mid, r);
    }
    st[v] = merge(st[2*v + 1], st[2*v + 2]);
}

Node get(int ql, int qr, int v, int l, int r) {
    if (qr <= l || r <= ql) {
        Node ret;
        return ret;
    }
    if (ql <= l && r <= qr) return st[v];
    int mid = l + (r - l) / 2;
    return merge(get(ql, qr, 2*v + 1, l, mid), get(ql, qr, 2*v + 2, mid, r));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    arr.resize(n);
    int maxEl = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxEl = max(maxEl, arr[i]);
    }
    build(0, 0, n);
    int q; cin >> q;
    for (int i = 0 ;i < q; i++) {
        int t; cin >> t;
        if (t == 3) {
            int l, r; cin >> l >> r;
            cout << get(l - 1, r, 0, 0, n).cnt << '\n';
        } else if (t == 1) {
            int k; cin >> k;
            if ((maxEl > 100 && k >= 1000) || (maxEl > 10 && k >= 10000) || (maxEl > 1 && k >= 100000) || (maxEl > 1000 && k >= 100) || (maxEl > 10000 && k >= 10) || (maxEl >= 100000 && k > 1)) {
                continue;
            }
            for (int i = 0; i < n; i++) {
                arr[i] = binpow(arr[i], k);
            }
            maxEl = binpow(maxEl, k);
            build(0, 0, n);
        } else {
            int 
        }
    }
    return 0;
}