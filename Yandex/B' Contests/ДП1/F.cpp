#include <bits/stdc++.h>

using namespace std;

struct Item {
    int w;
    float c;
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, w; cin >> n >> w;
    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        Item newItem;
        int nW; float nC; cin >> nW >> nC;
        newItem.w = nW; newItem.c = nC;
        items[i] = newItem;
    }
    for (int k = 0; k < n; k++) {
        vector<float> dp(w + 1);
        for (int i = 1; i <= n; i++) {
            if (i == k + 1) continue;
            for (int j = w; j >= items[i - 1].w; j--) {                
                if (dp[j - items[i - 1].w] >= 0) {
                    dp[j] = max(dp[j], dp[j - items[i - 1].w] + items[i - 1].c);
                }
            }
        }
        cout << dp[w] << '\n';
    }
    return 0;
}