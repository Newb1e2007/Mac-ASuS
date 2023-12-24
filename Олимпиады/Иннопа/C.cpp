#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }  
    int answ = 0; 
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < j; k++) {
                ll p = j - arr[i][j];
                if (j == 0 || i == n - 1) continue;
                if (arr[i][k] <= arr[i][j] || i + arr[i][k] - arr[i][j] > n - 1) continue;
                if (p - k >= 0 && arr[i + arr[i][k] - arr[i][j]][k] == arr[i][k] - arr[i][j]) answ++;
                else if (p - k < 0 && arr[i][j] - (p - k) > 0 && arr[i + arr[i][k] - arr[i][j]][k] == arr[i][k] - arr[i][j]) answ++;
            }
        }
    }*/
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < j; k++) {
                if (arr[i][k] > arr[i][j]) {
                    int x = arr[i][k];
                    int y = arr[i][j];
                    int z = x - y;
                    
                }

                /*if (x == y + z) {answ++; cout << i << ' ' << j << ' ' << k << '\n';}
                else if (x < z + y) {
                    int c = z + y - x;
                    if (min(x, min(y, z)) - c > 0) {answ++; cout << i << ' ' << j << ' ' << k << ' ' << add << '\n';}
                } else {
                    answ++; cout << i << ' ' << j << ' ' << k << '\n';
                }*/
            }
        }
    }  
    cout << answ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while(t--) solve();

    return 0;
}