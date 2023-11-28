#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    ll n, m; cin >> n >> m;
    cout << (n % m)*(m % n) + 1;
    return 0;
}