#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pic = pair<int, char>;
using ld = long double;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> bigg = {n - 1};
    /*string ss = s;
    sort(ss.begin(), ss.end(), greater<char>());
    int ind = 0;
    cout << ss << '\n';
    for (int i = 0; i < n; i++) {
        if (s[i] == ss[ind]) {
            ind++;
            bigg.push_back(i);
        }
    }*/
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] >= s[bigg.back()]) bigg.push_back(i);
    }
    reverse(bigg.begin(), bigg.end());
    int sz = bigg.size();
    int cnt = 0;
    int ind = sz - 1;
    while (s[bigg[0]] > s[bigg[ind]]) {
        cnt++;
        ind--;
    }
    for (int i = 0; i < sz / 2; i++) {
        char tmp = s[bigg[i]];
        s[bigg[i]] = s[bigg[sz - i - 1]];
        s[bigg[sz - i - 1]] = tmp;
    }
    cout << (is_sorted(s.begin(), s.end()) ? cnt : -1) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; 
    while (t--) solve();
    
    return 0;
}