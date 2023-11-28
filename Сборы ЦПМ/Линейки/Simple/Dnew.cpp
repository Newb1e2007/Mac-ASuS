#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int L = -1, R = 0;
    int Lansw = 0, Ransw = 0;
    ll summ = 0;
    ll answ = arr[0];
    for (int i = 0; i < n; i++) {
        summ += arr[R];
        if (summ <= 0) {
            L = R;
            summ = 0;
        }
        if (summ > answ) {
            answ = summ;
            Ransw = R;
            Lansw = L + 1;
        }
        R++;
    }
    cout << Lansw + 1 << '\n' << Ransw + 1;
    return 0;
}