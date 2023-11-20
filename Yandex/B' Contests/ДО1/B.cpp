#include <bits/stdc++.h>

using namespace std;

struct Node {
    int len = 1;
    int pref = 0;
    int suff = 0;
    int answ = 0;
};

int MAXN = 5e5;
vector<Node> st(4*MAXN);
vector<int> arr;

Node merge(const Node& l, const Node& r) {
    Node res;
    res.pref = l.pref;
    if (l.pref == l.len) {
        res.pref += r.pref;
    }
    res.suff = r.suff;
    if (r.suff == r.len) {
        res.suff += l.suff;
    }
    res.answ = max(max(l.answ, r.answ), l.suff + r.pref);
    res.len = l.len + r.len;
    return res;
}

void build (int v, int l, int r) {
    if (r - l == 1) {
        Node curV;
        if (arr[l] == 0) {
            curV.answ = 1; curV.pref = 1; curV.suff = 1;
        }
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
        if (x == 0) {
            curV.answ = 1;
            curV.suff = 1;
            curV.pref = 1;
        }
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

    int n; cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build(0, 0, n);
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        if (s == "UPDATE") {
            int i, x; cin >> i >> x;
            update(i - 1, x, 0, 0, n);
        } else {
            int l, r; cin >> l >> r;
            l--;
            cout << get(l, r, 0, 0, n).answ << '\n';
        }
    }
    return 0;
}