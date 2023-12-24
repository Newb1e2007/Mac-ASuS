/*Kerb9_*/
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ull = unsigned long long;
using ld = long double;
 
void solve() {
    int n, m; cin >> n >> m;
    vector<int> next(n);
    vector<int> dist(n);
    vector<int> arr(n);
    int sz = sqrt(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        int j = i;
        int pred = min(i / sz * sz  + sz, n);
        int curCnt = 0;
        int lastAdd = 0;
        while (j < pred) {
            lastAdd = arr[j];
            j += arr[j];
            curCnt++;
        }
        if (j < n) 
            next[i] = j;
        else 
            {next[i] = j - lastAdd;
            curCnt--;}
        dist[i] = curCnt;
    }
    for (int i = 0; i < m; i++) {
        int t; cin >> t;
        if (t == 0) {
            int a, b; cin >> a >> b;
            a--;
            int j = a;
            arr[a] = b;
            int pred = min(a / sz * sz + sz, n);
            int curCnt = 0;
            int lastAdd = 0;
            while (j < pred) {
                lastAdd = arr[j];
                j += arr[j];
                curCnt++;
            }
            if (j < n)
                next[a] = j;
            else 
                {next[a] = j - lastAdd;
                curCnt--;}
            dist[a] = curCnt;
                
            vector<bool> used(n);
            used[a] = 1;
            for (int k = a - 1; k >= a / sz * sz; k--) {
                if (k + arr[k] == a) {
                    next[k] = next[a];
                    dist[k] = dist[a] + 1;
                    used[k] = true;
                } else if (k + arr[k] >= n) {
                    continue;
                } else if (used[k + arr[k]]) {
                    next[k] = next[a];
                    dist[k] = dist[k + arr[k]] + 1;
                    used[k] = true;
                }
            }
        } else {
            int a; cin >> a;
            int v = a - 1;
            int curCnt = 0;
            while (v != next[v]) {
                curCnt += dist[v];
                v = next[v];
            }
            cout << v + 1 << ' ' << curCnt + 1 << '\n';
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}