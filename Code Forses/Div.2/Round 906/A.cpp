#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> arrV(n);
    map<int, int> arr;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        arrV[i] = a;
        arr[a]++;
    }
    if (arr.size() < 3) {
        //cout << "if\n";
        int minn = arrV[0];
        for (auto k : arr) {
            if (arr[minn] != k.second &&arr[minn] != k.second + 1 && arr[minn] != k.second - 1) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        return;
    } else {
        cout << "NO\n";
        return;
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; for (int i = 0; i < t; i++) {solve();}
    return 0;
}
