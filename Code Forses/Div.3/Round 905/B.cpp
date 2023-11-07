#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    string str; 
    //getline(cin, str);
    cin >> str;
    map<char, int> cnt;
    for (char el : str) {
        cnt[el]++;
    }
    int badEls = 0;
    for (auto sym : cnt) {
        if (sym.second % 2 == 1) {
            badEls++;
        }
    }
    if (badEls - 1 > k) 
        cout << "NO\n";
    //else if (badEls == k || badEls - 1 == k)
    else 
        cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}