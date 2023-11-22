#include <bits/stdc++.h>

using namespace std;

struct Node {
    int suff = 0;
    int maxSumm = 0; // >= 0 всегда
    int pref = 0;
    int allSumm = 0;
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
    build(2*v, l, mid);
    build(2*v + 1, mid, r);
    st[v] = merge(st[2*v], st[2*v + 1]);
}

void build(int i, int x, int v, int l, int r) {
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
        build(2*v, l, mid);
    } else {
        build(2*v + 1, mid, r);
    }
    st[v] = merge(st[2*v], st[2*v + 1]);
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
    return merge(get(ql, qr, 2*v, l, mid), get(ql, qr, 2*v + 1, mid, r));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}