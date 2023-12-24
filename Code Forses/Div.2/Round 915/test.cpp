#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pic = pair<int, char>;
using ld = long double;

void solve() {
    string s = "bac";
    sort(s.begin(), s.end());
    cout << s << '\n';
    sort(s.begin(), s.end(), greater<char>());
    cout << s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t; 
    while (t--) solve();
    
    return 0;
}