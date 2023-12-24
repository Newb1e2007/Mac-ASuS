#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ld = long double;
vector<set<int>> graph1, graph1Rev;
vector<set<int>> graph2, graph2Rev;
vector<int> used1, used2, order1, order2;

void dfs1(int v) {
    used1[v] = 1;
    for (auto u : graph1Rev[v]) {
        if (!used1[u]) {
            dfs1(u);
        }
    }
    order1.push_back(v);
}

void dfs2(int v, int color) {
    used1[v] = color;
    //cout << v << ' ' << color << " set\n";
    for (auto u : graph1[v]) {
        if (used1[u] == -1) {
            dfs2(u, color);
        }
    }
}

void dfs3(int v) {
    used2[v] = 1;
    for (auto u : graph2Rev[v]) {
        if (!used2[u]) {
            dfs3(u);
        }
    }
    order2.push_back(v);
}

void dfs4(int v, int color) {
    used2[v] = color;
    for (auto u : graph2[v]) {
        if (used2[u] == -1) {
            dfs4(u, color);
        }
    }
}

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    vector<int> q(n);
    used1.resize(n);
    used2.resize(n);
    graph1.resize(n);
    graph1Rev.resize(n);
    graph2.resize(n);
    graph2Rev.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];
        q[i]--;
    }
    for (int i = 0; i < n; i++) {
        graph1[i].insert(p[i]);
        graph1Rev[p[i]].insert(i);
        graph2[i].insert(q[i]);
        graph2Rev[q[i]].insert(i);
    }

    for (int i = 0; i < n; i++) {
        if (!used1[i]) {
            dfs1(i);
        }
    }
    reverse(order1.begin(), order1.end());
    int color1 = 0;
    used1.assign(n, -1);
    for (int v : order1) {
        if (used1[v] == -1) {
            dfs2(v, color1);
            color1++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!used2[i]) {
            dfs3(i);
        }
    }
    reverse(order2.begin(), order2.end());
    int color2 = 0;
    used2.assign(n, -1);
    for (int v : order2) {
        if (used2[v] == -1) {
            dfs4(v, color2);
            color2++;
        }
    }
    vector<vector<int>> comps1(color1), /*comps2(color2),*/ comps;
    for (int i = 0; i < n; i++) {
        comps1[used1[i]].push_back(i);
        //comps2[used2[i]].push_back(i);
    }
    /*for (int i = 0; i < color1; i++) {
        for (auto j : comps1[i]) {
            cout << j << ' ';
        }
        cout << '\n';
    }*/
    int color = 0;
    vector<int> used(color1);
    for (int i = 0; i < n; i++) {
        /*if (used1[i] == el_col[i].first && used2[i] == el_col[i].second) {
            comps[used1[i]].push_back(i);
        }*/
        int c1 = used1[i];
        if (!used[i]) {
            used[i] = 1;
            int c2 = used2[i];
            vector<int> curV;
            for (auto el : comps1[c1]) {
                if (used2[el] == c2) {
                    curV.push_back(el);
                    used[el] = 1;
                }
            }
            comps.push_back(curV);
            color++;
        }
    }
    /*cout << '\n';
    for (int i = 0; i < color; i++) {
        for (auto el : comps[i]) cout << el << ' ';
        cout << '\n';
    }*/
    ll answ = 0;
    for (int i = 0; i < color; i++) {
        int m = comps[i].size();
        if (m > 2) { 
            answ += (ll)(m * (m / 2)) + (ll)((m - 1) % 2 * ((m - 1) / 2 + 1));
        } else {
            answ += m - 1;
        }
        
    }
    cout << answ;
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int t = 1; // cin >> t;
    while(t--) solve();

    return 0;
}