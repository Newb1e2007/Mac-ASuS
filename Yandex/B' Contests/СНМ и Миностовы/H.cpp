#include <bits/stdc++.h>

using namespace std;

vector<int> p, sz;

struct Ask{
    int type;
    int v;
    int u;
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
    
    int n, m, k; cin >> n >> m >> k;
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    sz.resize(n, 1);
    for (int i = 0; i < m; i++) {int a, b; cin >> a >> b;}
    vector<Ask> asks(k);
    for (int i = 0; i < k; i++) {
        string pr; int v, u; cin >> pr >> u >> v;
        Ask a;
        a.u = u - 1; a.v = v - 1;
        if (pr == "cut") 
            a.type = 1;
        else 
            a.type = 0;
        asks[i] = a;
    }
    reverse(asks.begin(), asks.end());
    vector<string> answer;
    for (auto ask : asks) {
        if (ask.type == 1) {
            unite(ask.u, ask.v);
        } else {
            if (getRoot(ask.u) == getRoot(ask.v)) {
                answer.push_back("YES");
            } else {
                answer.push_back("NO");
            }
        }
    }
    reverse(answer.begin(), answer.end());
    for (auto el : answer) {
        cout << el << '\n';
    }
    return 0;
}