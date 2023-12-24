#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
using pii = pair<int, int>;

struct Node {
    int min = 1e9;
    int len = 0;
};

struct Event {
    int y1, y2;
    int x;
    int type;
};

const int MAXN = 1e6;
vector<Node> st(MAXN * 4);
vector<int> sp(MAXN * 4);
vector<int> arr;
vector<int> nums;
vector<int> dist;

int getCoord(int x) {
    return lower_bound(nums.begin(), nums.end(), x) - nums.begin();
}

Node merge(const Node& l, const Node& r) {
    Node res;
    if (l.min < r.min) {
        res.min = l.min;
        res.len = l.len;
    } else if (l.min == r.min) {
        res.min = l.min;
        res.len = l.len + r.len;
    } else {
        res.min = r.min;
        res.len = r.len;
    }
    return res;
}

void build(int v, int l, int r) {
    if (r - l == 1 ) {
        Node curV;
        curV.min = 0;
        curV.len = dist[l];  
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
    int mid = (r  + l) / 2;
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
    update(ql, qr, x, 2 * v + 1, l,mid);
    update(ql, qr, x, 2 * v + 2, mid, r);
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
    if (n == 0) {
        cout << 0;
        return 0;
    }
    vector<Event> eventsX;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        nums.push_back(y1);
        nums.push_back(y2);

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
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    sort(eventsX.begin(), eventsX.end(), [ & ] (Event i, Event j) {
        if (i.x == j.x) return i.type > j.type;
        return i.x < j.x;
    });
    for (int i = 1; i < (int)nums.size(); i++) {
        dist.push_back(nums[i] - nums[i - 1]);
    }
    int sz = dist.size();
    build(0, 0, sz);
    ull answ = 0;
    int last = -1e9 - 1;
    int bal = 0;
    for (Event e : eventsX) {
        if (bal != 0) {
            Node res = get(0, sz, 0, 0, sz);
            if (res.min == 0) {
                answ += (ull)(e.x - last) * (ull)(nums.back() - nums[0] - res.len);
            } else {
                answ += (ull)(e.x - last) * (ull)(nums.back() - nums[0]);
            }
        }
        last = e.x;
        bal += e.type;
        int y1 = getCoord(e.y1);
        int y2 = getCoord(e.y2);
        update(y1, y2, e.type, 0, 0, sz);
    }
    cout << answ;
}