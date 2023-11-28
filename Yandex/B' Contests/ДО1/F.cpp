#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Node {
    ll suff = 0;
    ll maxSumm = 0; // >= 0 всегда
    ll pref = 0;
    ll allSumm = 0;
};

const int MAXN = 3e5;
vector<Node> st(MAXN*4);    
vector<int> arr;

Node merge(const Node& l, const Node& r) {
    Node res;
    res.pref = max(l.pref, l.allSumm + r.pref);
    res.suff = max(r.suff, r.allSumm + l.suff);
    res.maxSumm = max(max(l.maxSumm, r.maxSumm), l.suff + r.pref);
    res.allSumm = l.allSumm + r.allSumm;
    return res;
}

void build(int v, int l, int r) {
    if (r - l == 1) {
        Node a;
        a.allSumm = arr[l];
        a.maxSumm = arr[l];
        a.suff = arr[l];
        a.pref = arr[l];
        st[v] = a;
        return;
    }
    int mid = l + (r - l) / 2;
    build(2*v + 1, l, mid);
    build(2*v + 2, mid, r);
    st[v] = merge(st[2*v + 1], st[2*v + 2]);
}

void update(int i, ll x, int v, int l, int r) {
    if (r - l == 1) {
        Node a; 
        a.allSumm = x;
        a.maxSumm = x;
        a.suff = x;
        a.pref = x;
        st[v] = a;
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
        Node a;
        return a;
    }
    if (ql <= l && r <= qr) {
        return st[v];
    }
    int mid = l + (r - l ) / 2;
    return merge(get(ql, qr, 2*v + 1, l, mid), get(ql, qr, 2*v + 2, mid, r));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build(0, 0, n);
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        if (s == "change") {
            int ps, val; cin >> ps >> val;
            update(ps - 1, (ll)val, 0, 0, n);
        } else {
            int l, r; cin >> l >> r;
            cout << get(l - 1, r, 0, 0, n).maxSumm << '\n';
        }
    }
    return 0;
}