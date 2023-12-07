#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n; cin >> n;
    vector<int> allP(n);
    vector<int> A(n + 1);
    vector<int> suff(n + 1); 
    for (int i = 0; i < n; i++) {
        cin >> allP[i];
    }   
    for (int i = n - 1; i >= 0; i--) {
        suff[i] = suff[i + 1] + allP[i];
    }
    for (int i = 0; i < n + 1; i++) {
        cin >> A[i];
    }
    int answ = 0;
    int a  =0;
    for (int i = 0; i <= n; i++) {
        if (i + A[i] <= n && suff[i] - suff[i + A[i]] >= answ) {
            a = i;
            answ = suff[i] - suff[i + A[i]];
        } else if (i + A[i] > n && suff[i] >= answ) {
            a = i;
            answ = suff[i];
        }
    }
    cout << answ << ' ' << a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}