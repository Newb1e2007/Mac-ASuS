#include <bits/stdc++.h>

using namespace std;

struct Node{
    int len = 0;
    int cnt = 0;
};

int MOD = 1e9 + 7;
const int MAXN = 1e5;
vector<Node> st(4*MAXN);
map<int, int> el_cnt;
vector<int> arr(1);

Node merge(const Node& l, const Node& r) {
    Node res; 
    if (l.len == r.len) {
        res.len = l.len + 1;
        res.cnt = l.cnt + r.cnt;
    } else if (l.len > r.len) {
        res.len = l.len + 1;
        res.cnt = l.cnt;
    } else {
        res.len = r.len + 1;
        res.cnt = r.cnt;
    }
    return res;
}

void update(int i, Node x, int v, int l, int r) {
    if (r - l == 1) {
        //Node a; a.len = x.first; a.cnt = x.second;
        st[v] = x;
        return; 
    } 
    int mid = l + (r - l) / 2;
    if (i < mid) {
        update(i, x, 2*v + 1, l, mid);
    } else {
        update(i, x, 2*v + 2, mid, r);
    }
    st[v] = merge(st[2*v + 1], st[2*v + 2]);
}

Node get(int ql, int qr, int v, int l, int r) {
    if (qr <= l ||  r <= ql) {
        Node a; return a;
    }
    if (ql <= l && r <= qr) {
        return st[v];
    }
    int mid = l + (r - l) / 2;
    return merge(get(ql, qr, 2*v + 1, l, mid), get(ql, qr, 2*v + 2, mid, r));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    cin >> arr[0];
    el_cnt[arr[0]] = 1;
    for (int i = 1; i < n; i++) {
        int a; cin >> a;
        if (a == arr[i - 1]) {
            el_cnt[a]++;
        } else {
            arr.push_back(a);
            el_cnt[a] = 1;
        }
    }
    for (int i = 0; i < arr.size(); i++) {

    }
    return 0;
}