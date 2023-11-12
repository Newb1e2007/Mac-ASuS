#include <bits/stdc++.h>

using namespace std;

vector<set<pair<int, int>>> graph, graphRev;
vector<int> used, order;
int n;

void dfs1(int v, int mid) {
    used[v] = 1;
    for (auto u : graph[v]) {
        if (u.second <= mid && !used[u.first]) {
            dfs1(u.first, mid);
        }
    }
    order.push_back(v);
}

void dfs2(int v, int mid, int color) {
    used[v] = color;
    for (auto u : graphRev[v]) {
        if (u.second <= mid && used[u.first] == -1) {
            dfs2(u.first, mid, color);
        }
    }
}

bool check(int mid) {
    used.assign(n, 0);
    order.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs1(i, mid);
        }
    }
    reverse(order.begin(), order.end());
    /*for (int i = 0; i < n; i++) {
        cout << order[i] << ' ';
    }
    cout << '\n';*/
    int color = 0;
    used.assign(n, -1);
    for (auto v : order) {
        if (used[v] == -1) {
            dfs2(v, color, mid);
            color++;
        }
    }
    /*for (int i = 0; i < n; i++) {
        cout << used[i] << ' ';
    }
    cout << " used\n";*/
    if (color == 1) {
        return true;
    } else {
        return true;
    }
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
    order.resize(n);
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
    /*for (int i = 0; i < n; i++) {
        for (auto u : graph[i]) {
            cout << i << ' ' << u.first << ' ' << u.second << '\n';
        }
    }
    return 0;*/
    if (maxVal == 0) {
        cout << 0;
        return 0;
    }
    int l = minVal - 1, r = maxVal + 1;
    while (r - l > 1) {
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

