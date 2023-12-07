#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    string s1, s2, s3; cin >> s1 >> s2 >> s3;
    vector<char> v1, v2, v3;
    for (auto c : s1) {
        if (v1.size() == 0 || v1.back() != c) v1.push_back(c);
    }
    for (auto c : s2) {
        if (v2.size() == 0 || v2.back() != c) v2.push_back(c);
    }
    for (auto c : s3) {
        if (v3.size() == 0 || v3.back() != c) v3.push_back(c);
    }
    if (v1 != v2 || v2 != v3 || v1 != v3) {
        cout << "IMPOSSIBLE";
        return;
    }
    string block = "";
    block += s1[0];
    vector<string> v1b, v2b, v3b;
    for (int i = 1; i < (int)s1.length(); i++) {
        //cout << i << ": \n";
        if (s1[i] == s1[i - 1]) {
            //cout << block << ' ';
            block += s1[i];
            //cout << block << '\n';
        } else {
            v1b.push_back(block);
            //cout << block << ' ';
            block = "";
            block += s1[i];
            //cout << block << '\n';
        }
    }
    v1b.push_back(block);
    block = "";
    block += s2[0];
    for (int i = 1; i < (int)s2.length(); i++) {
        if (s2[i] == s2[i - 1]) {
            block += s2[i];
        } else {
            v2b.push_back(block);
            block = "";
            block += s2[i];
        }
    }
    v2b.push_back(block);
    block = "";
    block += s3[0];
    for (int i = 1; i < (int)s3.length(); i++) {
        if (s3[i] == s3[i - 1]) {
            block += s3[i];
        } else {
            v3b.push_back(block);
            block = "";
            block += s3[i];
        }
    }
    v3b.push_back(block);
    string answer;
    for (int i = 0; i < (int)v1b.size(); i++) {
        if ((v1b[i].size() <= v2b[i].size() && v2b[i].size() <= v3b[i].size()) || (v1b[i].size() >= v2b[i].size() && v2b[i].size() >= v3b[i].size())) {
            answer += v2b[i];
        } else if ((v2b[i].size() <= v1b[i].size() && v1b[i].size() <= v3b[i].size()) || (v2b[i].size() >= v1b[i].size() && v1b[i].size() >= v3b[i].size())) {
            answer += v1b[i];
        } else {
            answer += v3b[i];
        }
    }
    cout << answer;
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}