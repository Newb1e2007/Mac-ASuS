#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

struct Node {
    int fo = 0, fc = 0, ans = 0;
};

const int MAXN = 1e5;
vector<Node> st(MAXN*4);
string s;

Node merge(const Node& l, const Node& r) {
    Node res;
    int tmp = min(l.fo, r.fc);
    res.ans = l.ans + r.ans + 
    
    return res;
}

void build(int v, int l, int r) {
    if (r - l == 1) {
        Node curV;
        if (s[l] == '(') curV.fo = 1;
        else curV.fc = 1;
        st[v] = curV;
        return;
    }
    int mid = l + (r - l) / 2;
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid, r);
}

Node get(int ql, int qr, int v, int l, int r) {
    if (qr <= l || r <= ql) {
        Node curV;
        return curV;
    }
    if (ql <= l && r <= qr) return st[v];
    int mid = l + (r - l) / 2;
    return merge(get(ql, qr, 2 * v + 1, l, mid), get(ql, qr, v * 2 + 2, mid, r));
}

void solve() {
    cin >> s;
    int n = s.length();
    build(0, 0, n);
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        cout << get(l - 1, r, 0, 0, n).ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}