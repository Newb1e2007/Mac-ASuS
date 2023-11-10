#include <bits/stdc++.h>

using namespace std;

vector<int> p, sz;

struct Edge {
    int v; 
    int u;
    int w;
};

int getRoot(int v) {
    if (p[v] == v) return v;
    return p[v] = getRoot(p[v]);
}

void unite(int a, int b) {
    a = getRoot(a);
    b = getRoot(b);

    if (a == b) {
        return;
    }
    if (sz[a] < sz[b]) {
        p[a] = b;
        sz[b] += sz[a];
    } else {
        p[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    p.resize(n + 1);
    sz.resize(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    } 
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        Edge e;
        e.v = a; e.u = b; e.w = w;
        edges[i] = e;
    }
    sort(edges.begin(), edges.end(), [ & ](Edge i, Edge j) {
        return i.w < j.w;
    });
    int answ = 0;
    for (int i = 0; i < m; i++) {
        if (getRoot(edges[i].v) != getRoot(edges[i].u)) {
            answ += edges[i].w;
            unite(edges[i].v, edges[i].u);
        } 
    }
    cout << answ;
    return 0;
}