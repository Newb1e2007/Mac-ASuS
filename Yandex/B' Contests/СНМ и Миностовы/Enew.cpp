#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using pdi = pair<double, int>;

double eps = 1e-4;

int countDist(int x1, int y1, int x2, int y2) {
    if (x1 < 0 && x2 < 0) {
        x2 += abs(x1);
        x1 = 0;
    }
    if (y1 < 0 && y2 < 0) {
        y2 += abs(y1);
        y1 = 0;
    }
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int n; cin >> n;
    vector<pii> vertexes(n);
    for (int i = 0; i < n; i++) {
        cin >> vertexes[i].first >> vertexes[i].second;
    }

    vector<double> dist(n, 1.0e9); dist[0] = 0.0;
    vector<int> p(n, -1);
    vector<bool> used(n);
    //used[0] = true;
    double answ = 0;

    for (int i = 0; i < n; i++) {
        int v = -1;
        //double curDist = 1.0e9;
        for (int j = 0; j < n; j++){ 
            //cout << dist[j] << ' ' << '\n';
            if ((v == -1 && !used[j]) || (!used[j] && dist[v] > dist[j])) {
                //cout << v << ' ' << j << '\n';
                v = j;
                //curDist = dist[j];
            }
        }
        //cout << v << '\n';
        used[v] = true;
        if (p[v] != -1) { 
            //cout << p[v] << ' ' << v << ' ' << answ << " before ";
            answ += sqrt(countDist(vertexes[p[v]].first, vertexes[p[v]].second,
                vertexes[v].first, vertexes[v].second));
            //cout << answ << " after\n";
        }
        for (int j = 0; j < n; j++) {
            double ndist = sqrt(countDist(vertexes[j].first, vertexes[j].second,
                vertexes[v].first, vertexes[v].second));
            if (dist[j] > ndist) {
                dist[j] = ndist;
                p[j] = v;
            }
        }
    }
    
    cout << fixed << setprecision(10) << answ;
}