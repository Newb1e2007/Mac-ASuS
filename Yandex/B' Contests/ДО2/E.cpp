#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

struct Node {
    ll min = 1e9;
    ll len = 0;
};

struct Event {
    ll y1, y2;
    ll x;
    ll type;
};

const ll MAXN = 1e6;
vector<Node> st(MAXN * 4);
vector<ll> sp(MAXN * 4);
vector<ll> arr;
vector<ll> nums;
vector<ll> dist;

ll getCoord(ll x) {
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

void build(ll v, ll l, ll r) {
    if (r - l == 1 ) {
        Node curV;
        curV.min = 0;
        curV.len = dist[l];  
        st[v] = curV;
        return;
    }
    ll mid = (r + l) / 2;
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid, r);
    st[v] = merge(st[2 * v + 1], st[2 * v + 2]);
}

void apply(ll x, ll v, ll l, ll r) {
    st[v].min += x;
    sp[v] += x;
}

void push(ll v, ll l, ll r) {
    ll x = sp[v];
    if (x == 0) return;
    sp[v] = 0;
    ll mid = (r  + l)/ 2;
    apply(x, 2 * v + 1, l, mid);
    apply(x, 2 * v + 2, mid, r);
}

void update(ll ql, ll qr, ll x, ll v, ll l, ll r) {
    if (qr <= l || r <= ql) {
        return;
    } 
    if (ql <= l && r <= qr) {
        return apply(x, v, l, r);
    }
    ll mid = (r + l) / 2;
    push(v, l, r);
    update(ql, qr, x, 2 * v + 1, l,mid);
    update(ql, qr, x, 2 * v + 2, mid, r);
    st[v] = merge(st[2 * v + 1], st[2 * v + 2]);
}

Node get(ll ql, ll qr, ll v, ll l, ll r) {
    if (qr <= l || r <= ql) {
        Node curV;
        return curV;
    } 
    if (ql <= l && r <= qr) {
        return st[v];
    }
    ll mid = (r + l) / 2;
    push(v, l, r);
    return merge(get(ql, qr, 2 * v + 1, l, mid), get(ql, qr, 2 * v + 2, l, r));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k; cin >> k >> n;
    if (n == 0) {
        cout << k * k;
        return 0;
    }
    vector<Event> eventsX;
    ll x1 = 0, y1 = 0, x2 = k, y2 = k;
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
    ll px1 = 0, py1 = 0, px2 = k, py2 = k;
    for (ll i = 0; i < n; i++) {
        char c; cin >> c;
        ll m; cin >> m;
        Event e;

        if (c == 'N') {
            y1 += m; y2 += m;
            e.type = 1;
            e.x = px1;
            e.y1 = py1;
            e.y2 = y2;
            eventsX.push_back(e);
            e.type = -1;
            e.x = x2;
            eventsX.push_back(e);
        } else if (c == 'S') {
            y1 -= m; y2 -= m;
            e.type = 1;
            e.x = px1;
            e.y1 = y1;
            e.y2 = py2;
            eventsX.push_back(e);
            e.type = -1;
            e.x = x2;
            eventsX.push_back(e);
        } else if (c == 'W') {
            x1 -= m; x2 -= m;
            e.type = 1;
            e.x = x1;
            e.y1 = py1;
            e.y2 = y2;
            eventsX.push_back(e);
            e.type = -1;
            e.x = px2;
            eventsX.push_back(e);
        } else if (c == 'E') {
            x1 += m; x2 += m;
            e.type = 1;
            e.x = px1;
            e.y1 = py1;
            e.y2 = y2;
            eventsX.push_back(e);
            e.type = -1;
            e.x = x2;
            eventsX.push_back(e);
        }
        nums.push_back(y1);
        nums.push_back(y2);

        e.type = 1;
        e.x = x1;
        e.y1 = y1;
        e.y2 = y2;
        eventsX.push_back(e);
        e.type = -1;
        e.x = x2;
        eventsX.push_back(e);

        px1 = x1; py1 = y1; px2 = x2; py2 = y2;
    }
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    sort(eventsX.begin(), eventsX.end(), [ & ] (Event i, Event j) {
        if (i.x == j.x) return i.type > j.type;
        return i.x < j.x;
    });
    for (ll i = 1; i < (ll)nums.size(); i++) {
        dist.push_back(nums[i] - nums[i - 1]);
    }
    ll sz = dist.size();
    build(0, 0, sz);
    ll answ = 0;
    ll last = -1e9 - 1;
    ll bal = 0;
    for (Event e : eventsX) {
        if (bal != 0) {
            Node res = get(0, sz, 0, 0, sz);
            if (res.min == 0) {
                answ += (ll)(e.x - last) * (ll)(nums.back() - nums[0] - res.len);
            } else {
                answ += (ll)(e.x - last) * (ll)(nums.back() - nums[0]);
            }
        }
        last = e.x;
        bal += e.type;
        ll y1 = getCoord(e.y1);
        ll y2 = getCoord(e.y2);
        update(y1, y2, e.type, 0, 0, sz);
    }
    cout << answ;
}