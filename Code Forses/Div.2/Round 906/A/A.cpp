#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> arr;
    int summ = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        summ += arr[i];
    }
    summ *= 2;
    int rem = summ % (n - 1);
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; for (int i = 0; i < t; i++) {solve();}
    return 0;
}
