#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;    
    vector<int> digits(4);
    int i = 0;
    while(i < 4) {
        int digit = n % 10;
        if (digit == 0) digit = 10;
        digits[i] = digit;
        n /= 10;
        i++;
    }
    reverse(digits.begin(), digits.end());
    int cnt = digits[0];
    cnt += abs(digits[1] - digits[0]) + 1;
    cnt += abs(digits[2] - digits[1]) + 1;
    cnt += abs(digits[3] - digits[2]) + 1;
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}