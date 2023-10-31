#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string n; getline(cin, n);
    int maxLen = 1, curLen = 1;
    
    for (int i = 1; i < n.size(); i++) {
        if (n[i] != n[i - 1]) {
            maxLen = max(maxLen, curLen);
            curLen = 1;
        } else {
            curLen++;
        }
    }
    maxLen = max(curLen, maxLen);
    cout << maxLen;
    return 0;
}