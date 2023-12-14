#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Node {
    int min = 1e9, cnt = 0;
};

struct Event {
    int y1, y2;
    int x;
    int type;
};

const int MAXN = 1e5;
vector<Node> st(MAXN * 4);
vector<int> sp(MAXN * 4);
vector<int> arr;

Node merge(const Node& l, const Node& r) {
    Node res;
    if (l.min < r.min) {
        res.min = l.min;
        res.cnt = l.cnt;
    } else if (l.min == r.min) {
        res.min = l.min;
        res.cnt = l.cnt + r.cnt;
    } else {
        res.min = r.min;
        res.cnt = r.cnt;
    }
    return res;
}

void build(int v, int l, int r) {
    if (r - l == 1 ){
        Node curV;
        curV.min = 0;
        curV.cnt = 1;
        st[v] = curV;
        return;
    }
    int mid = (r + l) / 2;
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid, r);
    st[v] = merge(st[2 * v + 1], st[2 * v + 2]);
}

void apply(int x, int v, int l, int r) {
    st[v].min += x;
    sp[v] += x;
}

void push(int v, int l, int r) {
    int x = sp[v];
    if (x == 0) return;
    sp[v] = 0;
    int mid = (r  + l)/ 2;
    apply(x, 2 * v + 1, l, mid);
    apply(x, 2 * v + 2, mid, r);
}

void update(int ql, int qr, int x, int v, int l, int r) {
    if (qr <= l || r <= ql) {
        return;
    } 
    if (ql <= l && r <= qr) {
        return apply(x, v, l, r);
    }
    int mid = (r + l) / 2;
    push(v, l, r);
    update(ql, qr, x, v, l,mid);
    update(ql, qr, x, v, mid, r);
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
    int mid = (r + l) / 2;
    push(v, l, r);
    return merge(get(ql, qr, 2 * v + 1, l, mid), get(ql, qr, 2 * v + 2, l, r));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<Event> eventsX;
    int minY = 1e9, maxY = -1e9;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

        minY = min(minY, y1);
        maxY = max(maxY, y2);

        Event e;
        e.type = 1;
        e.x = x1;
        e.y1 = y1;
        e.y2 = y2;
        eventsX.push_back(e);
        e.type = -1;
        e.x = x2;
        eventsX.push_back(e);
    }
    sort(eventsX.begin(), eventsX.end(), [ & ] (Event i, Event j) {
        if (i.x == j.x) return i.type > j.type;
        else return i.x < j.x;
    });
    cout << maxY << ' ' << minY << '\n';
    ll answ = 0;
    int last = -1e9 - 1;
    int bal = 0;
    for (Event e : eventsX) {
        if (bal != 0) {
            Node res = get(minY, maxY + 1, 0, minY, maxY + 1);
            cout << res.min << ' ' << res.cnt << '\n';
            if (res.min == 0) {
                answ += (ll)abs(abs(e.x) - abs(last)) * (ll)(abs(abs(maxY) - abs(minY)) + 1 - res.cnt);
            } else {
                answ += (ll)abs(abs(e.x) - abs(last)) * (ll)(abs(abs(maxY) - abs(minY)) + 1);
            }
        }
        bal += e.type;
        update(e.y1, e.y2, e.type, 0, minY, maxY + 1);
    }
    cout << answ;
}