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
    int minV = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] < arr[minV]) {
            minV = i;
        }
    }
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        ll w; cin >> w;
        Edge e; e.u = a - 1; e.v = b - 1; e.w = w;
        edges.push_back(e);
    }
    
    for (int i = 0; i < n; i++) {
        if (i == minV) continue;
        Edge e; e.u = i; e.v = minV; e.w = arr[i] + arr[minV];
        edges.push_back(e);
    }
    sort(edges.begin(), edges.end(), [ & ](Edge i, Edge j){
        return i.w < j.w;
    });
    ll answ = 0;
    for (auto edge : edges) {
        if (getRoot(edge.u) != getRoot(edge.v)) {
            answ += edge.w;
            unite(edge.u, edge.v);
        }
    }
    cout << answ;
    return 0;
}