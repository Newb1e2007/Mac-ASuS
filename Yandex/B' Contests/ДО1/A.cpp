#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
vector<int> st(4*MAXN);
vector<int> arr(MAXN);
map<int, int> el_pos;

void build(int v, int l, int r) {
    if (r - l == 1) {
        return;
    }
    int mid = l + (r - l) / 2;
    build(2*v + 1, l, mid);
    build(2*v + 2, mid, r);
    st[v] = max(st[2*v + 1], st[2*v + 2]);
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
    st[v] = max(st[2*v + 1], st[2*v + 2]);
}

int get(int ql, int qr, int v, int l, int r) {
    if (qr <= l || r <= ql) return 0;
    if (ql <= l && r <= qr) return st[v];
    int mid = l + (r - l) / 2;
    return max(get(ql, qr, 2*v + 1, l, mid), get(ql, qr, 2*v + 2, mid, r));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        el_pos[x] = i + 1;
        update(i, x, 0, 0, n);
    }
    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        int l, r; cin >> l >> r;
        l--;
        int answ = get(l, r, 0, 0, n);
        cout << answ << ' ' << el_pos[answ] << '\n';
    }
    return 0;
}