#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Event
{
    int x; int tipe; int num;
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<Event> arr;
    arr.reserve(2*n);
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        Event a; a.x = l; a.tipe = 1; a.num = i + 1;
        Event b; b.x = r; b.tipe = -1; b.num = i + 1;
        arr.push_back(a);
        arr.push_back(b);
    }
    sort(arr.begin(), arr.end(), [ & ] (Event a, Event b) {
        return (a.x < b.x || (a.x == b.x && a.tipe > b.tipe));
    });

    int cur = 0, minn = 1e9, cnt = 0, prev = -2e9; int numS, answF, answS;
    int lastprev = -2e9, lastnumS;
    for (Event e : arr) {
        if  (e.tipe == 1) {
            if (e.x != lastprev) {
                cur = 0;
                prev = e.x;
                numS = e.num;
            }
        } else if (prev != -2e9){
            cur = abs(prev) - abs(e.x);
            if (cur < minn && cur != 0) {
                minn = cur; 
                answS = numS;
                answF = e.num;
            }
            prev = -1;
            cur = 0;
        }
        //cnt += e.tipe;
    }
    if (answF == answS) {
        cout << 0;
    } else {
        cout << answF << ' ' << answS;
    }
}