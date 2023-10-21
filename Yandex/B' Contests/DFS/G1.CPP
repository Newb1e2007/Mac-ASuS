#include <bits/stdc++.h>

using namespace std;

vector<int> used;
vector<set<int>> graph;

void dfs(set<int> &currAnsw, int v) {
    used[v] = 1;
    currAnsw.insert(v + 1);
    for (int u : graph[v]) {
        if (!used[u]) {
            dfs(currAnsw, u);
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a - 1].insert(b - 1);
        graph[b - 1].insert(a - 1);
    }
    vector<set<int>> answ;
    used.resize(n);
    for (int i = 0; i < n; i++) {
        set<int> currAnsw;
        if (!used[i]) {
            dfs(currAnsw, i);
            //answ.push_back(currAnsw);
            for (int el : currAnsw) {
                if (currAnsw.count(el) > 1) {
                    cout << "No";
                    return 0;
                }
            }
        }
    }
    /*cout << answ.size() << '\n';
    for (auto ks : answ) {
        cout << ks.size() << '\n';
        for (int k : ks) {
            cout << k << ' ';
        }
        cout << '\n';
    }*/
    return 0;
}