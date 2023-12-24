#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int MAXN = 1e3;
vector<int> st(4*MAXN);
vector<int> arr;

int merge(const int l, const int r) {
    return gcd(l, r);    
}

void build (int v, int l, int r) {
    if (r - l == 1) {
        st[v] = arr[l];
        return;
    }
    int mid = l + (r - l) / 2;
    build(2*v + 1, l, mid);
    build(2*v + 2, mid, r);
    st[v] = merge(st[2*v + 1], st[2*v + 2]);
}

int get(int ql, int qr, int v, int l, int r) {
    if (qr <= l || r <= ql) {
        return 0;
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
    for (int i = 0; i  <n; i++) {
        cin >> arr[i];
    }
    build(0, 0, n);
    cout << get(0, n, 0, 0, n);
}