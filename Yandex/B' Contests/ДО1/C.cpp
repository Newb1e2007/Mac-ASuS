#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n;
vector<int> st(4*MAXN);
vector<int> arr;

void build(int v, int l, int r) {
    if (r - l == 1) {
        st[v] = l;
        return;
    }
    int mid = l + (r - l) / 2;
    build(2*v + 1, l, mid);
    build(2*v + 2, mid, r);
    if (arr[st[2*v + 1]] > arr[st[2*v + 2]]) {
        st[v] = st[2*v + 1];
    } else {
        st[v] = st[2*v + 2];
    }
}

int get(int ql, int qr, int v, int l, int r) {
    if (qr <= l || r <= ql) return n;
    if (ql <= l && r <= qr) return st[v];
    int mid = l + (r - l) / 2;
    int a = get(ql, qr, 2*v + 1, l, mid), b = get(ql, qr, 2*v + 2, mid, r);
    if (arr[a] > arr[b]) {
        return a; 
    } else {
        return b;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    arr.resize(n + 1);
    arr[n] = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build(0, 0, n);
    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        int l, r; cin >> l >> r; 
        l--;
        cout << get(l, r, 0, 0, n) + 1 << '\n';
    }
    return 0;
}