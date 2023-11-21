#include <bits/stdc++.h>

using namespace std;

struct Node {
    int summ = 0;
    int len = 1;
};

const int MAXN = 1e5;
vector<Node> st(MAXN*4);
vector<int> arr;

Node merge(const Node& l, const Node& r) {
    Node res;
    if (l.len % 2 == 0) {
        res.summ = l.summ + r.summ;
    } else {
        res.summ = l.summ - r.summ;
    }
    res.len = l.len + r.len;
    return res;
}

void build(int v, int l, int r) {
    if (r - l == 1) {
        Node curV; curV.summ = arr[l];
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
        Node curV; curV.summ = x;
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
        Node ret; ret.len = 0;
        return ret;
    }
    if (ql <= l && r <= qr) return st[v];
    int mid = l + (r - l) / 2;
    return merge(get(ql, qr, 2*v + 1, l, mid), get(ql, qr, 2*v + 2, mid, r));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("signchange.in", "r", stdin);
    freopen("signchange.out", "w", stdout);

    int n; cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build(0, 0, n);
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int c; cin >> c;
        if (c == 0) {
            int i, j; cin >> i >> j; 
            i--;
            update(i, j, 0, 0, n);
        } else {
            int l, r; cin >> l >> r;
            l--;
            cout << get(l, r, 0, 0, n).summ << '\n';
        }
    }
    return 0;
}