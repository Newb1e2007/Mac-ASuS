#include <bits/stdc++.h>

using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    map<char, int> Symb_Cnt;
    for (auto c : s) {
        Symb_Cnt[c]++;
    }
    vector<vector<char>> ans;
    int iter = 0;
    for (auto el : Symb_Cnt) {
        el.second--;
        int len = 1;
        ans[iter].push_back(el.first);
        while (len < s.size()) {
            for (auto nel : Symb_Cnt) {
                if (!nel.second) continue;

            }
        }
        for (auto c : s) {
            Symb_Cnt[c]++;
        }
        iter++;
    }
    return 0;
}