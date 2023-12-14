#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

struct Node {
    int l = 0;
    int r = 0;
};

const int MAXN = 5e5;
vector<Node> st(MAXN * 4);
vector<int> days;
int m;

Node merge(const Node& l, const Node& r) {
    Node res;
    res.l = max(l.l, r.l);
    res.r = min(l.r, r.r);
    if (res.l > res.r) res.r = res.l;
    return res;
}

void build(int v, int l, int r) {
    if (r - l == 1) {
        Node curV;
        curV.l = 0; curV.r = m;
        st[v] = curV;
        return;
    }
    int mid = l + (r - l) / 2;
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid, r); 
    st[v] = merge(st[2 * v + 1], st[2 * v + 2]);
}

void update(int i, pii x, int v, int l, int r) {
    if (r - l == 1) {
        Node curV; 
        curV.l = x.first;
        curV.r = x.second;
        st[v] = curV;
        return;
    }
    int mid = l + (r - l) / 2;
    if (i < mid) {
        update(i, x, 2 * v + 1, l, mid);
    } else {
        update(i, x, 2 * v + 2, mid, r);
    }
    st[v] = merge(st[2 * v + 1], st[2 * v + 2]);
}

Node get(int ql, int qr, int v, int l, int r) {
    if (qr <= l || r <= ql) {
        Node curV;
        return curV;
    }
    if (ql <= l && r <= qr) {
        return st[v];
    }
    int mid = l + (r - l) / 2;
    return merge(get(ql, qr, 2 * v + 1, l, mid), get(ql, qr, 2 * v + 2, mid, r));
}

void solve() {
    int n; cin >> n >> m;
    days.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> days[i];
    }
    build(0, 0, n - 1);

    //int k = 0;
    int lastT= days[0]; 
    for (int i = 1; i < n; i++) {
        if (days[i] - lastT > 2 * m) {
            cout << -1;
            return;
        }
        pii x;
        if (days[i] - lastT < m) {
            x = {0, m};
        } else {
            x.first = days[i] - lastT - m + 1;
            x.second = m;
        }
        update(i, x, 0, 0, n - 1);
    }

    /*int k = 0;
    int curD = 0, lastD = 0;
    for (int i = 0; i < n; i++) {
        cout << k << '\n';
        if (k >= m) {
            cout << -1;
            return;
        }
        if (days[i] < k) {
            curD = (k - days[i] + m - 1) / m * -1;
        } else {
            curD = (days[i] - k) / m;
        }
        //if ((days[i] - k) % m == 0 && days[i] - k != 0) curD++;
        if (days[i] < k) {
            curD = (k - days[i] + m - 1) / m * -1; 
        }
        cout << i << ' ' << curD  << ' ' << lastD << ' ' << k << '\n'; 
        if (i == 0 || curD - lastD <= 1) {
            lastD = curD;
            continue;
        } else {
            if (curD - lastD > 2) {
                cout << -1 << " ex";
                return;
            }
            int newk = days[i] - ((lastD + 1) * m + k) + 1;  // (- 1 2) (- - -) (6 - -) (- 10 11) (12 - -)
            if (newk <= k) k++;
            else k = newk;
            if (days[i] - ((lastD + 1) * m + k) == 0) {
                k++;
            }
            i = -1;
            curD = 0; 
            lastD = 0;
        }
    }*/
    Node x = get(0, n - 1, 0, 0, n - 1);
    if (x.l == x.r) {
        cout << -1 << " aboba";
    } else {
        cout << x.l;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; // cin >> t;
    while (t--) solve();

    return 0;
}