#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        arr[a - 1]++; arr[b - 1]++;
    }
    for (int v : arr) {
        cout << v << ' ';
    }
    return 0;
}