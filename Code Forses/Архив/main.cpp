#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

vector<int> p, sz;

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
    int n, m; cin >> n >> m;
    //vector<int> arr(n);
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    sz.resize(n, 1);
    for (int i = 0; i < n; i++) {
        //cin >> arr[i];
        int x; cin >> x;
        unite(i, x - 1);
        //p[i] = x - 1;
    }
    //cout << "aboba\n";
    
    for (int i = 0; i < m; i++) {
        //cout << "emm\n";
        int t; cin >> t;
        if (t == 0) {
            int a, b; cin >> a >> b;
            //p[a - 1] = b - 1;
            unite(a - 1, b - 1);
        } else {
            int a; cin >> a;
            cout << getRoot(a) + 1 << ' ' << sz[a] << '\n'; 
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}
