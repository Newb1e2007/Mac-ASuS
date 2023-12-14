#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;

const int MAXN = 1e5;
vector<int> st(MAXN*4);
vector<int> arr;
int n;

void build(int v, int l, int r, bool flag) {
    if (r - l == 1) {
        st[v] = arr[l];
        return;
    }
    int mid = (r + l) / 2;
    build(2 * v + 1, l, mid, !flag);
    build(2 * v + 2, mid, r, !flag);
    if (flag) {
        st[v] = st[2 * v + 1] | st[2 * v + 2];
    } else {
        st[v] = st[2 * v + 1] ^ st[2 * v + 2];
    }
}

void update(int i, int x, int v, int l ,int r, bool flag) {
    if (r - l == 1) {
        st[v] = x;
        return;
    }
    int mid = (l + r)  /2;
    if (mid > i) {
        update(i, x, 2 * v + 1, l, mid, !flag);
    } else {
        update(i, x, 2 * v + 2, mid, r, !flag);
    }
    if (flag) {
        st[v] = st[2 * v + 1] | st[2 * v + 2];
    } else {
        st[v] = st[2 * v + 1] ^ st[2 * v + 2];
    }
}

int get(int ql, int qr, int v, int l, int r, bool flag) {
    if (qr <= l || r <= ql) {
        return 0;
    } 
    if (ql <= l && r <= qr) {
        return st[v];
    }
    int mid = (r + l) / 2;
     if (flag) {
        return get(ql, qr, 2 * v + 1, l, mid, !flag) | get(ql, qr, 2 * v + 2, mid, r, !flag);
    } else {
        return get(ql, qr, 2 * v + 1, l, mid, !flag) ^ get(ql, qr, 2 * v + 2, mid, r, !flag);
    }
    //return get(ql, qr, 2 * v + 1, l, mid) | get(ql, qr, 2 * v + 2, mid, r);
}

void solve() {
    int m; cin >> n >> m;
    arr.resize((1 << n));
    for (int i = 0; i < (1 << n); i++) {
        cin >> arr[i];
    }
    bool flag;
    if (n % 2 == 1) {
        flag = true;
    } else {
        flag = false;
    }
    build(0, 0, (1 << n), flag);
    for (int i = 0; i <  m; i++) {
        int p, b; cin >> p >> b;
        update(p - 1, b, 0, 0, (1 << n), flag);
        cout << get(0, (1 << n), 0, 0, (1 << n), flag) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t; 
    while (t--) solve();
    
    return 0;
}
