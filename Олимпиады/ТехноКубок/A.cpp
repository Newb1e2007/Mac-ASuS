#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;
    vector<ll> A(n);
    vector<ll> arr;
    ll allCnt = 0;
    //vector<int> arr(n);
    /*for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }*/
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        allCnt += A[i];
        for (int j = 0; j < A[i]; j++) {
            ll b; cin >> b;
            arr.push_back(b);
        }
    }
    sort(arr.begin(), arr.end(), greater<int>());
    sort(A.begin(), A.end());
    ld res = 0;
    int lastInd = 0;
    for (int i = 0; i < n; i++) {
        //cout << a << " new\n";
        int a = 0;
        if (i != n - 1) a = 2;
        else {
            a = allCnt - 2 * (n - 1);
        }
        ll cnt = 0;
        int k = 0;
        while(k < a) {
            k++;
            //cout << k << ' ' << lastInd << ' ' << arr[lastInd] << '\n';
            cnt += arr[lastInd];
            lastInd++;
        }
        res += (ld)cnt / (ld)a;
    }
    cout << fixed << setprecision(10) << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; // cin >> t;
    while(t--) solve();

    return 0;
}