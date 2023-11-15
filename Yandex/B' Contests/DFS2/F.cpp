#include <bits/stdc++.h>

using namespace std;
//vector<vector<int>> nGraphForCheck, nGraphForCheckRev;
vector<vector<pair<int, int>>> graph;
vector<pair<pair<int, int>, int>> nGraph;
vector<int> used, powers;

void dfs(int v) {
    for (auto u : graph[v]) {
        if (!used[u.second]) {
            powers[v]++;
            //nGraphForCheck[v].push_back(u.first);
            //nGraphForCheckRev[u.first].push_back(v);
            used[u.second] = 1;
            nGraph.push_back(make_pair(make_pair(v, u.first), u.second));
            dfs(u.first);
        }
    }
}

/*void topsort(int v) {
    used[v] = 1;
    for (int u : nGraphForCheck[v]) {
        if (!used[u]) topsort(u);
    }
    order.push_back(v);
}

void dfs2(int v) {
    used[v] = 0;
    for (int u : nGraphForCheckRev[v]) {
        if (used[u]) dfs2(u);
    }
}*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin  >> n >> m;
    graph.resize(n);
    used.resize(m);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a - 1].push_back(make_pair(b - 1, i));
        graph[b - 1].push_back(make_pair(a - 1, i));
    }
    for (auto v : graph) {
        if (v.size() < 2) {
            cout << 0;
            return 0;
        }
    }
    nGraph.reserve(n);
    powers.resize(n);
    //nGraphForCheck.resize(n);
    //nGraphForCheckRev.resize(n);
    dfs(0);
    int cnt = 0;
    for (int p : powers) {
        if (p % 2 == 1) {
            cnt++;
        }
    }
    if (cnt == 2 || cnt == 0) {
        //used.assign(n, 0);
        //order.reserve(n);
        //topsort(0);
        //if (order.size() < n) {cout << 0; return 0;}
        //reverse(order.begin(), order.end());
        //int color = 0;
        /*for (int v : order) {
            if (used[v]) {
                color++;
                dfs2(v);
            }
        }
        if (color > 1) {
            cout << 0;
            return 0;
        }*/
        sort(nGraph.begin(), nGraph.end(), [ & ](pair<pair<int, int>, int> i, pair<pair<int, int>, int> j){
            return i.second < j.second;
        });
        for (auto edge : nGraph) {
            cout << edge.first.first + 1 << ' ' << edge.first.second + 1 << '\n';
        }
    } else {
        cout << 0;
    }
    return 0;
}