#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> arr = {1};
    int div = 2;
    while (n > 1) {
        while (n % div == 0) {
            arr.push_back(div);
            n /= div;
        }
        div++;
    }
    //reverse(arr.begin(), arr.end());
    if (arr.size() == 2) cout << "prime";
    else {
        cout << "composite";
    }
}