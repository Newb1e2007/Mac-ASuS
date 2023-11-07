#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> dp;
ll mod = 1e9 + 7;

int solve(int n) {
    if (dp[n] > 0) {
        return dp[n];
    }
    for (int i = 1; i <= 6; i++) {
        if (n >= i) {
            dp[n] += solve(n - i);
            dp[n] %= mod;
        }
    }
    return dp[n];
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    dp.resize(n + 1);
    dp[0] = 1;
    cout << solve(n);    
    return 0;
}