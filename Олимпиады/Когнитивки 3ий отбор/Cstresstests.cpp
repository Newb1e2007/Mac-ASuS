#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

struct Test{
    int n, m;
    vector<pii> g;
};

vector<vector<int>> graph;
vector<int> cnt;

void solve_smart() {
    int n, m; cin >> n >> m;
    graph.resize(n);
    cnt.resize(n);
    //vector<vector<int>> cntEv(n, vector<int>(n));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[v - 1].push_back(u - 1);
        graph[u - 1].push_back(v - 1);
        cnt[u - 1]++;
        cnt[v - 1]++;
        //cntEv[u - 1][v - 1]++;
        //cntEv[v - 1][u - 1]++;
        //if (cnt[v - 1] < minAnsw) {answ = v; minAnsw = cnt[v - 1];}
        //if (cnt[u - 1] < minAnsw) {answ = u; minAnsw = cnt[u - 1];}
    }
    //priority_queue<pii> notVis;
    set<pii, greater<pii>> notVis;
    for (int i = 0; i < n; i++) {
        notVis.emplace(cnt[i], i);
    }
    int answ = 0;
    while (!notVis.empty()) {
        int d = notVis.begin()->first;
        int v = notVis.begin()->second;
        notVis.erase({d, v});
        vector<int> nowDel = {v};
        //cout << cnt[4] << " aaaa\n";
        while (true) {
            int d1 = notVis.begin()->first;
            int v1 = notVis.begin()->second;
            if (d1 == d) {
                nowDel.push_back(v1);
                notVis.erase({d1, v1});
            } else {
                break;
            }
        }
        for (int i : nowDel) {cnt[i] = -1;}
        for (auto el : nowDel) {
            for (int u : graph[el]) {
                notVis.erase({cnt[u], u});
                cnt[u]--;
                //cout << u << ' ' << cnt[u] << "; ";
                if (cnt[u] > 0)
                    notVis.emplace(cnt[u], u);
            }
        }
        answ++;
    }
    for (int i = 0; i < n; i++) {
        if (cnt[i] == 0) {
            answ++;
            break;
        }
    }
    cout << answ << '\n';
}