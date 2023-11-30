#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
double eps = 1e-5;
vector<int> p, sz;

struct Edge
{
    int v, u;
    double w;  
};


int dist(int x1, int y1, int x2, int y2) {
    if (x1 < 0 && x2 < 0) {
        x2 += abs(x1);
        x1 = 0;
    }
    if (y1 < 0 && y2 < 0) {
        y2 += abs(y1);
        y1 = 0;
    }
    return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}

int getRoot(int v) {
    if (p[v] == v) return v;
    return p[v] = getRoot(p[v]);
}

void unite(int a, int b) {
    a = getRoot(a);
    b = getRoot(b);
    if (a == b) return;
    if (sz[a] > sz[b]) swap(a, b);
    p[a] = b;
    sz[b] += sz[a];
}

void solve() {
    int n; cin >> n;
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    sz.resize(n, 1);
    vector<pair<int, int>> vertexes(n);
    for (int i = 0; i < n; i++) {
        cin >> vertexes[i].first >> vertexes[i].second;
    }
    vector<Edge> edges;
    edges.reserve(n*(n - 1)/2);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            Edge e; e.u = i; e.v = j; e.w = sqrt((double)dist(vertexes[i].first, vertexes[i].second, vertexes[j].first, vertexes[j].second));
            edges.push_back(e);
        }
    }
    sort(edges.begin(), edges.end(), [ & ](Edge i, Edge j){
        //return i.w < j.w;
        return j.w - i.w > -eps;
    });
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int a,b; cin >> a >> b;
        unite(a - 1, b - 1);
    }
    double answ = 0;
    for (Edge edge : edges) {
        if (getRoot(edge.u) != getRoot(edge.v)) {
            answ += edge.w;
            unite(edge.u, edge.v);
        }
    }
    cout << fixed << setprecision(6) << answ;
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}