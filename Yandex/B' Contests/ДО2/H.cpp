#include <bits/stdc++.h>

using namespace std;

struct Node {
    multiset<int> ms;
};

const int MAXN = 1e5;
vector<Node> st(4 * MAXN);
vector<int> arr;

Node merge(const Node& l, const Node& r) {
    Node res;
    if (l.ms.size() < r.ms.size()) {
        for (int el : l.ms) {
            res.ms.insert(el);
        }
    }
}

void build(int v, int l, int r) {
    if (r - l == 1) {
        st[v].ms.insert(arr[l]);
    }
    int mid = (r + l) / 2;
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid, r);
    st[v] = merge(st[2 * v + 1], st[2 * v + 2]);
}

void

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;

}