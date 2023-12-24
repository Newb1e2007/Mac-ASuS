#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
vector<int> vis;

struct Event {
    int x;
    int num;
    int type;
    int s;
};

const int MAXN = 1e5;
vector<Node> st(MAXN * 4);

struct Node {
    int fMax = 0;
    int fMaxInd = 0;
    int fMaxIndArr = 0;
    int sMax = 0;
    int sMaxInd = 0;
    int sMaxIndArr = 0;
};

Node merge(const Node& l, const Node& r) {
    Node res;
    if (l.fMax > r.fMax) {
        res.fMax = l.fMax;
        res.fMaxInd = l.fMaxInd;
        if (l.sMax > r.fMax) {
            res.sMax = l.sMax;
            res.sMaxInd = l.sMaxInd;
        } else {
            res.sMax = r.fMax;
            res.sMaxInd = r.fMaxInd;
        }
    } else {
        res.fMax = r.fMax;
        res.fMaxInd = r.fMaxInd;
        if (l.fMax < r.sMax) {
            res.sMax = r.sMax;
            res.sMaxInd = r.sMaxInd;
        } else {
            res.sMax = l.fMax;
            res.sMaxInd = l.fMaxInd;
        }
    }
    return res;
}

void build(int v, int l, int r) {
    if (r - l == 1) {
        st[v] = 0;
    }
    int mid = (r + l) / 2;
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid, r);
    st[v] = merge(st[2 * v + 1], st[2 * v + 2]);
}

void update(int i, pii x, int v, int l, int r) {
    if (r - l == 1) {
        Node curV;
        curV.fMax = x.first;
        curV.fMaxInd = x.second;
        st[v] = curV;
    }
    int mid = (r + l) / 2;
    if (i < mid)  {
        update(i, x, 2 * v + 1, l, mid);
    } else {
        update(i, x, 2 * v + 2, mid, r);
    }
    st[v] = merge(st[2 * v + 1], st[2 * v + 2]);
}

Node get(int ql, int qr, int v, int l, int r) {
    if (qr <= l || r <= qr) {
        Node curV;
        return curV;
    } 
    if (ql <= l && r <= qr) {
        return st[v];
    }
    int mid = (r + l) / 2;
    return merge(get(ql, qr, 2 * v + 1, l, r), get(ql, qr, 2 * v + 2, l, r));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<Event> events;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        Event e;
        e.num = i;
        e.type = 1;
        e.x = a;
        events.push_back(e);
        e.type = -1;
        e.x = b;
        e.s = a;
        events.push_back(e);
    }
    sort(events.begin(), events.end(), [ & ](Event i, Event j) {
        if (i.x == j.x) return i.type > j.type;
        return i.x < j.x;
    });

    int bal = 0;
    int fAd = 0, sAd = 0;
    vis.resize(2 * n);
    build(0, 0, 2*n);
    int i = 0;
    vector<int> answ;
    map<int, int> event_start;
    for (Event e : events) {
        bal += e.type;
        update(i, {bal, e.x}, 0, 0, 2*n);
        if (e.type == -1) {
            if (sAd < e.s) {
                Node res = get(event_start[e.num], i + 1, 0, 0, 2 * n);
                answ.push_back(res.fMaxInd);
                answ.push_back(res.sMaxInd);
                update(i, {0, res.sMaxInd}, )
            }
        } else {
            event_start[e.num] = i;
        }
        i++;
    }


    return 0;
}