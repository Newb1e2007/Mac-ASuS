#include <bits/stdc++.h>

using namespace std;

int summS(string s, int strt = 0) {
    int answ = 0;
    for (int i = strt; i < s.length(); i++) {
        answ += (s[i] - '0');
    }
    return answ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    vector<vector<vector<string>>> table(5, vector<vector<string>>(45));
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int summ = summS(s);
        table[s.length() - 1][summ - 1].push_back(s);
        arr[i] = s;
    }
    int answ = 0;
    for (string s : arr) {
        int curSumm = summS(s);
        int curLen = s.length();
        for (int l = (curLen + 1) / 2; l <= curLen; l++) {
            int rSumm = summS(s, l);
            int lSumm = curSumm - rSumm;
            if (lSumm - rSumm > 0) {
                answ += table[l - 1][lSumm - rSumm - 1].size();
            }
            if (rSumm - lSumm > 0 && l != curLen) {
                answ += table[curLen - l - 1][rSumm - lSumm - 1].size();
            }
        }
    }
    cout << answ;
}