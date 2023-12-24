#include <bits/stdc++.h>

using namespace std;

bool next_perm(vector<int> &arr, vector<int> &divs, int k, int n, int ind) {
    for (int i = k - 1; i >= 0; i++) {
        if ()
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    set<int> divs;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.insert(i);
            divs.insert(n / i);
        }
    }
    if ((int)divs.size() < k) {
        cout << 0;
        return 0;
    }


}