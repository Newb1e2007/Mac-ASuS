#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;

void solve() {
    int n, k; cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    if (k >= 3) {
        cout << 0 << '\n';
        return;
    }
    vector<ll> difs(n - 1);
    for (int i = 0; i < n - 1; i++) {
        difs[i] = abs(arr[i] - arr[i + 1]);
    }
    if (k == 1) {
        sort(difs.begin(), difs.end());
        //sort(arr.begin(), arr.end());
        cout << min(arr[0], difs[0]) << '\n';
    } else {
        map<ll, int> el_cnt;
        for (int i = 0; i < n; i++) {
            el_cnt[arr[i]]++;
        }
        for (int i = 0; i < n - 1; i++) {
            if (el_cnt[difs[i]] >= 1) {
                cout << 0 << '\n';
                return;
            }
        }
        sort(difs.begin(), difs.end());
        ll curMin = min(arr[0], difs[0]);

        for (int i = 0; i < n; i++) {
            int j;
            if (el_cnt[i] > 1) {
                j = i;
            } else {
                j = i + 1;
            }
            for (j = 0; j < n; j++) {
                /*
                while (add < curMin) {
                    if (el_cnt[arr[j] - arr[i] + add] >= 1 || el_cnt[arr[j] + arr[i] + add] >= 1) {
                        curMin = add;
                        break;
                    } else {
                        add++;
                    }
                }*/
                for (int k = 0; k < n; k++) {
                    if (abs(abs(arr[k] - arr[j]) - arr[i]) < curMin) {
                        curMin = abs(abs(arr[k] - arr[j]) - arr[i]);
                        if (curMin == 0) {
                            cout << 0 << '\n';
                            return;
                        }
                    } else {
                        break;
                    }
                }
            }
        }

        cout << curMin << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; 
    while (t--) solve();
    
    return 0;
}