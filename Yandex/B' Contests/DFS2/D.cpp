#include <bits/stdc++.h> 

using namespace std;
using ll = long long;

vector<set<int>> graphRev;
vector<int> used, order;
vector<ll> allP;
int n;

void dfs(int v) {
    used[v] = 1;
    for (int u : graphRev[v]) {
        if (!used[u]) dfs(u);
    }
    order.push_back(v);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    graphRev.resize(n);
    used.resize(n);
    allP.resize(n);
    order.reserve(n); 
    for (int i = 0; i < n; i++) {
        cin >> allP[i];
    } 
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int a; cin >> a;
            graphRev[i].insert(a - 1);
        }
    }
    dfs(0);
    ll answ = 0;
    for (int el : order) {answ += allP[el];}
    cout << answ << ' ' << order.size() << '\n';
    for (auto el : order) {cout << el + 1 << ' ';}
    cout.flush();
    return 0;
}