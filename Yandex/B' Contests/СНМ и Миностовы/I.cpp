#include <bits/stdc++.h>

using namespace std;    
using ll = unsigned long long;

vector<int> p, sz;

struct Edge {
    int u, v;
    ll w;
};

int getRoot(int v) {
    if (p[v] == v) return v;
    return p[v] = getRoot(p[v]);
}

void unite(int a, int b) {
    a = getRoot(a);
    b = getRoot(b);
    if (a == b) return;
    if (sz[a] > sz[b]) swap(a, b);
    sz[b] += sz[a];
    p[a] = b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    p.resize(n);
    sz.resize(n, 1);
    iota(p.begin(), p.end(), 0);
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<vector<ll>> off(n, vector<ll>(n));
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        ll w; cin >> w;
        off[a - 1][b - 1] = w;
        off[b - 1][a - 1] = w;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << off[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    vector<Edge> edges;
    edges.reserve((ll)n*(ll)(n - 1)/(ll)2);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            Edge e; e.u = i; e.v = j;
            if (off[i][j] != 0) e.w = min(off[i][j], arr[i] + arr[j]);
            else 
                e.w = arr[i] + arr[j];
            edges.push_back(e);
        }
    }
    for (auto el : edges) {
        cout << el.u << ' ' << el.v << ' ' << el.w << '\n';
    }
    sort(edges.begin(), edges.end(), [ & ](Edge i, Edge j){
        return i.w < j.w;
    });
    ll answ = 0;
    cout << '\n';
    for (ll i = 0; i < (ll)n*(ll)(n - 1)/2; i++) {
        if(getRoot(edges[i].u) == getRoot(edges[i].v)) {
            answ += edges[i].w;
            cout << edges[i].u << ' ' << edges[i].v << ' ' << edges[i].w << '\n';
            unite(edges[i].u, edges[i].v);
        }
    }
    cout << answ;
    return 0;
}