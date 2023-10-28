#include <bits/stdc++.h>

using namespace std;

struct Item {
    int w;
    float c;
    //bool isAllowed  = true;
};


int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int n, w; cin >> n >> w;
    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        Item newItem;
        int nW; float nC; cin >> nW >> nC;
        //cin >> newItem.w >> newItem.c; //maxW += newItem.w;
        newItem.w = nW; newItem.c = nC;
        items[i] = newItem;
    }
    /*vector<vector<int>> dp(n + 1, vector<int>(maxC + 1));
    for (int i = 1; i <= maxC; i++) {dp[0][i] = 1e9;}
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= maxC; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= C[i - 1]) {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - C[i - 1]] + W[i - 1]);
            }
        }
    }*/
    vector<float> dp(w + 1); for (int i = 1; i <= w; i++) {dp[i] = -1;}
    for (int k = 0; k < n; k++) {
        //items[k].isAllowed = false;
        for (int i = 1; i <= n; i++) {
            if (i == k + 1) continue;
            for (int j = w; j >= items[i - 1].w; j--) {                
                    //cout << dp[j] << ' ' << dp[j - items[i - 1].w] << ' ' << items[i - 1].c << '\n';
                if (dp[j - items[i - 1].w] >= 0) {
                    dp[j] = max(dp[j], dp[j - items[i - 1].w] + items[i - 1].c);
                }
                //dp[j] = max(dp[j], dp[j - items[i - 1].w] + items[i - 1].c);
            }
        }
        /*for (int i = 0; i <= w; i++) {
            cout << dp[i] << ' ';
        }
        return 0;*/
        cout << dp[w] << '\n';
        //items[k].isAllowed = true;
    }
    return 0;
}