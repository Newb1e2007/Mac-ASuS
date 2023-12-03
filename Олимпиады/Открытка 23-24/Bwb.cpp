#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

struct Node {
    int v;
};

vector<Node> st;
vector<int> arr;

void build (int v, int l, int r) {
    if (r - l == 1) {
        Node a; a.v = arr[l];
        st[v] = a;
        return;
    }
    int mid = l + (r - l) / 2;
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid, r);
}

void build (int i, int x, int v, int l, int r) {
    if (r - l == 1) {
        Node a; a.v = arr[l];
        st[v] = a;
        return;
    }
    int mid = l + (r - l) / 2;
    if (i < mid) build(2 * v + 1, l, mid);
    else build(2 * v + 2, mid, r);
}

int get(int ql, int qr, int v, int l, int r) {
    if (qr <= l || r <= ql) {
        return 0;
    }
    if (ql <= l && r <= qr) {
        return st[v].v;
    }
    int mid = l + (r - l) / 2;
    return get(ql ,qr, 2 * v + 1, l, mid) + get(ql, qr, 2 * v + 2, mid, r);
}

void solve() { 
    int n; cin >> n;
    arr.resize((1 << n));
    for (int i = 0; i < (1 << n); i++) {
        cin >> arr[i];
    }
    build(0, 0, (1 << 20));
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        if (t == 1) {
            //cout << "aboba\n";
            int l, r, k, v; cin >> l >> r >> k >> v;
            
        } else {
            int l, r, k; cin >> l >> r >> k;
            bitset<(1 << 30)> bitK(k);
            int cntK = 0;
            /*for (int i = 0; i < (int)bitK.size(); i++) {
                if (bitK.test(i) == 0) {
                    break;
                }
                cntK++;
            }*/
            /*int per = (1 << cntK);
            int fEl = l ^ k;
            int lEl = r ^ k;*/
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}