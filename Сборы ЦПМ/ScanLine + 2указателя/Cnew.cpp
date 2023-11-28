#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> pref(24*60*60 + 1);
    for (int i = 0; i < n; i++) {
        int h, m, s, h2, m2, s2; cin >> h >> m >> s >> h2 >> m2 >> s2;
        int time1 = h*60*60 + m*60 + s; 
        int time2 = h2*60*60 + m2*60 + s2;
        if (time1 >= time2) {
            pref[1]++;
            pref[time1]--;
            pref[time2]++;
            //pref[24*60*60]--;
        } else {
            pref[time1]++;
            pref[time2]--;
        }
    }
    for (int i = 1; i <= 24*60*60; i++) {
        pref[i] = pref[i - 1] + pref[i];
    }
    int maxx = 0;
    //int cur = 0;
    for (int i = 1; i <= 24*60*60; i++) {
        if (pref[i] == n) {
            maxx++;
        }
        
    }
    cout << maxx;
    return 0;
}