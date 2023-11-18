#include <bits/stdc++.h>

using namespace std;
using coords = pair<int, int>;
using pic = pair<int, coords>;

vector<vector<coords>> p;
int INF = 1e9;
int n;

int dijkstra(coords s, coords f) {
    vector<int> X = {-2, -2, -1, -1, 1, 1, 2, 2};
    vector<int> Y = {1, -1, 2, -2, 2, -2, 1, -1};
    vector<vector<int>> dist(n, vector<int>(n, INF)); dist[s.first][s.second] = 0;
    priority_queue<pic, vector<pic>, greater<pic>> notVis;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            coords crds; crds.first = i; crds.second = j;
            notVis.emplace(dist[i][j], crds);
        }
    }
    while (!notVis.empty()){
        auto [d, crds] = notVis.top();
        notVis.pop();
        if (crds.first == f.first && crds.second == f.second) break;
        for (int i = 0; i < 8; i++) {
            if (crds.first + X[i] >= 0 && crds.first + X[i] < n && crds.second + Y[i] >= 0 && 
            crds.second + Y[i] < n && (dist[crds.first + X[i]][crds.second + Y[i]] > d + 1)) {
                dist[crds.first + X[i]][crds.second + Y[i]] =  d + 1;
                p[crds.first + X[i]][crds.second + Y[i]] = crds;
                coords v; v.first = crds.first + X[i]; v.second = crds.second + Y[i];
                notVis.emplace(dist[crds.first + X[i]][crds.second + Y[i]], v);
            }
        }
    }
    return dist[f.first][f.second];
}    

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    p.resize(n, vector<coords>(n));
    coords s, f; s.first = x1 - 1; s.second = y1 - 1; f.first = x2 - 1; f.second = y2 - 1;
    p[s.first][s.second] = {-1, -1};
    int answ = dijkstra(s, f);
    cout << answ << '\n';

    coords v = {f.first, f.second};
    vector<coords> path;
    while (v.first != -1 && v.second != -1) {\
        path.push_back(v);
        v = p[v.first][v.second];
    }
    reverse(path.begin(), path.end());
    for (auto el : path) {
        cout << el.first + 1 << ' ' << el.second + 1 << '\n';
    }
    return 0;
}       