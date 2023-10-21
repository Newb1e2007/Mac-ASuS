#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> findLR(vector<int>& hs, int n) {
    vector<pair<int, int>> answ(n);
    vector<pair<int, int>> st;
    for (int i = n - 1; i >= 0; i--) {
        while(!st.empty() && st.back().first >= hs[i]) {
            st.pop_back();
        }
        if (!st.empty()) {
            answ[i].second = st.back().second;
        }
        st.push_back(make_pair(hs[i], i));
    }
    vector<pair<int, int>> stn;
    for (int i = 0; i < n; i++) {
        while(!stn.empty() && stn.back().first >= hs[i]) {
            stn.pop_back();
        }
        if (!stn.empty()) {
            answ[i].first = stn.back().second;
        }
        stn.push_back(make_pair(hs[i], i));
    }
    return answ;
}

int solveHist(vector<int>& hs, int n) {
    int answ = 0;
    vector<pair<int, int>> lr = findLR(hs, n);
    for (int i = 0; i < n; i++) {
        if (lr[i].second == 0) lr[i].second = n;
        if (lr[i].first == 0 && hs[i] <= hs[0]) lr[i].first = -1;
        int newAnsw = hs[i] * (lr[i].second - lr[i].first - 1);
        answ = max(answ, newAnsw);
    }
    return answ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> dArr(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int el;
            cin >> el;
            dArr[i][j] = (el + 1)%2;
        }
    }
    vector<int> hist(m);
    for (int i = 0; i < m; i++) {
        hist[i] = dArr[0][i];
    }
    int answ = solveHist(hist, m);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dArr[i][j] == 1) {
                hist[j]++;
            } else {
                hist[j] = 0;
            }
        }
        answ = max(answ, solveHist(hist, m));
    }
    cout << answ;

    return 0;
}