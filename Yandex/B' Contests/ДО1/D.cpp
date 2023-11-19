#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
vector<int> st(4*MAXN);
vector<int> arr;

int nod(int a, int b) {
    if (b == 0) {return a;}
    else {return nod(b, a%b);}
}

void build(int v, int l, int r) {
    if (r - l == 1) {
        st[v] = arr[l];
        return;
    }
    int mid = l + (r - l) / 2;
    build(2*v + 1, l, mid);
    build(2*v + 2, mid, r);
    st[v] = nod(st[2*v + 1], st[2*v + 2]);
}

void update(int i, int x, int v, int l, int r) {
    if (r - l == 1) {
        st[v] = x;
        return;
    }
    int mid = l + (r - l) / 2;
    if (i < mid) {
        update(i, x, 2*v + 1, l, mid);
    } else {
        update(i, x, 2*v + 2, mid, r);
    }
    st[v] = nod(st[2*v + 1], st[2*v + 2]);
    
}

int get(int ql, int qr, int v, int l, int r) {
    if (qr <= l || r <= ql) return 0;
    if (ql <= l && r <= qr) return st[v];
    int mid = l + (r - l) / 2;
    return nod(get(ql, qr, 2*v + 1, l, mid), get(ql, qr, 2*v + 2, mid, r));
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
        char c; cin >> c;
        if (c == 's') {
            int l, r; cin >> l >> r;
            l--;
            cout << get(l, r, 0, 0, n) << ' ';
        } else {
            int i, x; cin >> i >> x; 
            i--;
            update(i, x, 0, 0, n);
        }
    }
    return 0;
}