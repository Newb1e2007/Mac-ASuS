#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

struct Node
{
    int max = 0;
    int coords;
};

struct Event
{
    int x;
    int type;
    int y1, y2;
};


const int MAXN = 2e6;
vector<Node> st(MAXN*4);
vector<int> sp(MAXN*4);
vector<int> arr;

int get_coords(int x) {
    return lower_bound(arr.begin(), arr.end(), x) - arr.begin();
}

Node merge(const Node& l, const Node& r) {
    Node res;
    if (l.max > r.max) {
        res.max = l.max;
        res.coords = l.coords;
    } else if (l.max == r.max) {
        res.max = l.max;
        res.coords = l.coords;
    } else {
        res.max = r.max;
        res.coords = r.coords;
    }
    //cout << l.max << ' ' << r.max << ' ' << res.max << '\n';
    return res;
}

void build(int v, int l, int r) {
    if (r - l == 1 ) {
        //cout << v << ' ' << l << "  build\n";
        Node curV;
        curV.max = 0;
        curV.coords = arr[l];  
        st[v] = curV;
        return;
    }
    int mid = (r + l) / 2;
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid, r);
    st[v] = merge(st[2 * v + 1], st[2 * v + 2]);
}

void apply(int x, int v, int l, int r) {
    st[v].max += x;
    sp[v] += x;
}

void push(int v, int l, int r) {
    int x = sp[v];
    if (x == 0) return;
    sp[v] = 0;
    int mid = (r + l) / 2;
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
    update(ql, qr, x, 2 * v + 1, l, mid);
    update(ql, qr, x, 2 * v + 2, mid, r);
    st[v] = merge(st[2 * v + 1], st[2 * v + 2]);
}

Node get(int ql, int qr, int v, int l, int r) {
    if (qr <= l || r <= ql) {
        Node curV;
        curV.max = 0;
        curV.coords = 0;
        return curV;
    }
    if (ql <= l && r <= qr) {
        return st[v];
    }
    int mid = (r + l) / 2;
    push(v, l, r);
    return merge(get(ql, qr, 2 * v + 1, l, mid), get(ql, qr, 2 * v + 2, mid, r));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<Event> eventsX;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        arr.push_back(y1);
        arr.push_back(y2);
        
        Event e;
        e.x = x1;
        e.type = 1;
        e.y1 = y1;
        e.y2 = y2;
        eventsX.push_back(e);
        e.x = x2;
        e.type = -1;
        eventsX.push_back(e);
    }

    sort(arr.begin(), arr.end());
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
    sort(eventsX.begin(), eventsX.end(), [ & ] (Event i, Event j) {
        if (i.x == j.x) return i.type > j.type;
        return i.x < j.x;
    });
    int sz = arr.size();
    build(0, 0, sz);
    //cout << "after build\n";

    int answ = 0;
    pii coords;
    for (Event e : eventsX) {    
        //cout << "==================\n";
        int y1 = get_coords(e.y1);
        int y2 = get_coords(e.y2);
        update(y1, y2 + 1, e.type, 0, 0, sz);
        //cout << e.x << ' ' << e.y1 << ' ' << e.y2 << ' ' << e.type << '\n';
        Node curV = get(0, sz, 0, 0, sz);
        //cout << st[3].max << ' ' << st[5].max << ' ' << st[6].max << '\n'; 
        //cout << curV.max << ' ' << curV.coords << ' ' << answ << " ===\n";
        if (curV.max > answ) {
            answ = curV.max;
            coords = {e.x, curV.coords};
        } 
    }
    cout << answ << '\n';
    cout << coords.first << ' ' << coords.second;

    return 0;
}