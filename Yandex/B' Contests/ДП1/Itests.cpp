#include <bits/stdc++.h>

using namespace std;

const int MIN = 1;
const int MAX = 60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Test {
    vector<pair<int, int>> W;
    int n;
    int maxW;
};

struct Answ{
    int canWe = 1;
    map<int, int> answ;
};


Answ solve_smart(int n, int maxW, vector<pair<int, int>>& W) {
    Answ answ;
    if (maxW % 3 == 0) {
        maxW /= 3;
    } else {
        answ.canWe = -1;
        return answ;
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(maxW + 1)); dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = maxW; j >= 0; j--) {
            dp[i][j] = dp[i - 1][j];
            if (j >= W[i - 1].first) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - W[i - 1].first];
            }
        }
    }
    if (!dp[n][maxW]) {
        answ.canWe = -1;
        return answ;
    }
    map<int, int> W_heaps;
    for (int i = 1; i <= n; i++) {
        W_heaps[i] = 0;
    }
    int x = n, y = maxW, cnt = 0;
    while (x != 0) {
        if (dp[x - 1][y] == dp[x][y]) {
            x--;
        } else {
            W_heaps[W[x - 1].second] = 1;
            cnt++;
            y -= W[x - 1].first;
            x--;
        }
    }
    vector<pair<int, int>> W1;
    for (auto w : W) {
        if (!W_heaps[w.second]) {
            W1.push_back(w);
        }
    }

    vector<vector<bool>> dp1(n + 1 - cnt, vector<bool>(maxW + 1)); dp1[0][0] = 1;
    for (int i = 1; i <= n - cnt; i++) {
        for (int j = maxW; j >= 0; j--) {
            dp1[i][j] = dp1[i - 1][j];
            if (j >= W1[i - 1].first) {
                dp1[i][j] = dp1[i - 1][j] + dp1[i - 1][j - W1[i - 1].first];
            }
        }
    }
    if (!dp1[n - cnt][maxW]) {
        answ.canWe = -1;
        return answ;
    }
    x = n - cnt;
    y = maxW;
    int cnt1 = 0;
    while (x != 0) {
        if (dp1[x - 1][y] == dp1[x][y]) {
            x--;
        } else {
            W_heaps[W1[x - 1].second] = 2;
            cnt1++;
            y -= W1[x - 1].first;
            x--;
        }
    }
    answ.answ = W_heaps;
    return answ;
}

Test genTests() {
    uniform_int_distribution<int> n_dist(MIN, MAX);
    uniform_int_distribution<int> w_dist(MIN, MAX);
    int n = n_dist(rng), maxW = 0;
    vector<pair<int, int>> w(n);
    for (int i = 0; i < n; i++) {
        w[i].first = w_dist(rng);
        maxW += w[i].first;
        w[i].second = i + 1;
    }
    Test newTest;
    newTest.n = n; newTest.maxW = maxW; newTest.W = w;
    return newTest;
}

bool check(Answ& answer, Test& test) {
    if (answer.canWe != -1) {
        int summ1 = 0, summ2 = 0, summ3 = 0;
        for (auto el : answer.answ) {
            if (el.second == 1) {
                summ1 += test.W[el.first - 1].first;
            } else if (el.second == 2) {
                summ2 += test.W[el.first - 1].first;
            } else {
                summ3 += test.W[el.first - 1].first;
            }
        }
        if (summ1 == summ2 && summ2 == summ3 && summ1 + summ2 + summ3 == test.maxW) {
            return true;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("output.txt", "w", stdout);
    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        Test newTest = genTests();
        Answ newAnsw = solve_smart(newTest.n, newTest.maxW, newTest.W);
        if (!check(newAnsw, newTest)) {
            cout << "WA in test " << i + 1 << ". n = " << newTest.n << ", W = ";
            for (auto w : newTest.W) {
                cout << w.first << ' ';
            }
            return 0;
        }
    }
    cout << "No fault, you so good brooo";
    return 0;
}