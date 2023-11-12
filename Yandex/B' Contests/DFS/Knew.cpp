#include <bits/stdc++.h>

using namespace std;

vector<set<pair<int, int>>> graph, graphRev;
vector<int> used;
int n;

void dfs1(int v, int mid) {
    used[v] = 1;
    for (auto u : graph[v]) {
        if (u.second <= mid && !used[u.first]) {
            dfs1(u.first, mid);
        }
    }
}

void dfs2(int v, int mid) {
    used[v] = 0;
    for (auto u : graphRev[v]) {
        if (u.second <= mid && used[u.first]) {
            dfs2(u.first, mid);
        }
    }
}

bool check(int mid) {  // 4000
    used.assign(n, 0);
    dfs1(0, mid);
    for (auto v : used) {
        if (!v) return false;
    }
    dfs2(0, mid);
    for (auto v : used) {
        if (v) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("avia.in", "r", stdin);
    freopen("avia.out", "w", stdout);
    cin >> n;
    int maxVal = 0, minVal = 1e9;
    graph.resize(n);
    graphRev.resize(n);
    used.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int currCost; cin >> currCost;
            if (currCost) {
                maxVal = max(maxVal, currCost);
                minVal = min(minVal, currCost);
                graph[i].insert({j, currCost});
                graphRev[j].insert({i, currCost});
            }
        }
    }
    if (maxVal == 0) {
        cout << 0;
        return 0;
    }
    int l = minVal - 1, r = maxVal + 1;
    while (r - l > 1) {  // 29*4000
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (r > maxVal) {
        cout << maxVal;
    } else {
        cout << r;
    }
    return 0;
}

