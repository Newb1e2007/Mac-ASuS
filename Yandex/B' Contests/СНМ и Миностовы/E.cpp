#include <bits/stdc++.h>

using namespace std;
vector<int> p, sz;
double answ = 0;

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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    
    return 0;
}