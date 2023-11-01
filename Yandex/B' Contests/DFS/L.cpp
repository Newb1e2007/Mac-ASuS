#include <bits/stdc++.h>

using namespace std;

struct vert {
    int v;
    int color;
    int tag;
};

vector<set<pair<int, char>>> graph; 
//vector<pair<int, int>> tags;
map<int, pair<set<int>, set<int>>> tags; 

void dfs1(int v, int color) {
    //tags[v].first = color;
    tags[v].first.insert(color);
    for (auto u : graph[v]) {
        if (!tags[u.first].first.count(color) && u.second == 'R') {
            dfs1(u.first, color);
        }
    }
    return;
}

void dfs2(int v, int curColor, int lastColor) {
    //tags[v].second = curColor;
    tags[v].second.insert(curColor);
    for (auto u : graph[v]) {
        if (!tags[u.first].second.count(curColor) && u.second == 'B') {
            if (tags[u.first].first.count(lastColor) > 0) {
                cout << "YES";
                exit(0);
            } else {
                dfs2(u.first, curColor, lastColor);
            }
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    graph.resize(n);
    //tags.resize(n);
    for (int i = 1; i <= n - 1; i++) {
        char c;
        for (int j = 1; j <= n - i; j++) {
            cin.get(c);
            /*if (c == 'R') {
                graph[i - 1].insert({i + j - 1, 1});    
            } else {
                graph[i].insert({i + j - 1, 2});
            }*/
            graph[i].insert({i + j - 1, c});
        }
    }

    int color = 0;
    for (int i = 0; i < n; i++) {
        if (!tags[i].first.size()) {
            dfs1(i, ++color);
        }
    }

    int color = 0;
    for (int i = 0; i < n; i++) {
        if (!tags[i].second.size()) {
            dfs2(i, --color, tags[i].first);
        }
    }
    
}