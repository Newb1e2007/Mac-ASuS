#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e9;
vector<int> st(4*MAXN);
vector<int> arr;

void build(int v, int l, int r) {
    if (r - l == 1) {
        st[v] = 0;
        return;
    }
    int mid = l + (r - l) / 2;
    build(2*v + 1, l, mid);
    build(2*v + 2, mid, r);
    st[v] = st[2*v + 1] + st[2*v + 2];
}

void update(int i, int v, int l, int r) {
    if (r - l == 1) {
        st[v]++;
        return;
    }
    int mid = l + (r - l) / 2;
    if (i < mid) {
        update(i, 2*v + 1, l, mid);
    } else {
        update(i, 2*v + 2, mid, r);
    }
    st[v] = st[2*v + 1] + st[2*v + 2];
}

int get(int ql, int qr, int v, int l, int r) {
    if (qr <= l || r <= ql) return 0;
    if (ql <= l && r <= qr) return st[v];
    int mid = l + (r - l) / 2;
    return get(ql, qr, 2*v + 1, l, mid) + get(ql, qr, 2*v + 2, mid, r);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    arr.resize(MAXN);
    int maxEl;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        arr[a] = 0;
    }
    build(0, 0, n);

}