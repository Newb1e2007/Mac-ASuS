#include <bits/stdc++.h>

using namespace std;
using ll = long long;
map<int, int> el_pos;

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> arr(n); 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> El_min(n);
    int maxx = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] >= arr[maxx]) {
            maxx = i;
        }
        el_pos[i] = maxx;
    }
    int Lansw = 0, Ransw = 1; 
    ll answ = 0;
    for (int i = 0; i < n - k; i++) {
        if ((ll)arr[i] + (ll)arr[el_pos[i + k]] > answ) {
            answ = (ll)arr[i] + (ll)arr[el_pos[i + k]];
            Lansw = i + 1; Ransw = el_pos[i + k] + 1;
        }
    }
    cout << Lansw << ' ' << Ransw;
    return 0;
}