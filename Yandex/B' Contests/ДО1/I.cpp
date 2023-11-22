#include <bits/stdc++.h>

using namespace std;
int MAXN = 1e6;
vector < int > st(4*MAXN);
vector < int > arr;

void build(int v, int l, int r) {
    if (r - l == 1) {
        st[v] = 0;
        return;
    }
    int mid = l + (r - l) / 2;
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid, r);
    st[v] = st[2 * v + 1] + st[2 * v + 2];
}

void update(int i, int x, int v, int l, int r) {
    if (r - l == 1) {
        st[v] += x;
        return;
    }
    int mid = l + (r - l) / 2;
    if (i < mid) {
        update(i, x, 2 * v + 1, l, mid);
    } else {
        update(i, x, 2 * v + 2, mid, r);
    }
    st[v] = st[2 * v + 1] + st[2 * v + 2];
}

int get(int ql, int qr, int v, int l, int r) {
    if (qr <= l || r <= ql) return 0;
    if (ql <= l && r <= qr) return st[v];
    int mid = l + (r - l) / 2;
    return get(ql, qr, 2 * v + 1, l, mid) + get(ql, qr, 2 * v + 2, mid, r);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    arr.resize(n);
    int maxEl = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxEl = max(maxEl, arr[i]);
    }
    build(0, 0, maxEl);
    unsigned long long answ = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > arr[i]) {
                update(arr[j], -1, 0, 0, maxEl);
                answ += (unsigned long long)get(arr[j], maxEl, 0, 0, maxEl);
            }
        }
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[i]) {
                update(arr[j], 1, 0, 0, maxEl);
            }
        }
        update(arr[i], 1, 0, 0, maxEl);
    }
    cout << answ;
    return 0;
}