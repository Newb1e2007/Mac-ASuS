#include <bits/stdc++.h>

using namespace std;

struct Event
{
    int x; int tipe;
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<Event> arr;
    arr.reserve(2*n);
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        Event a; a.x = l; a.tipe = 1;
        Event b; b.x = r; b.tipe = -1;
        arr.push_back(a);
        arr.push_back(b);
    }
    sort(arr.begin(), arr.end(), [ & ] (Event a, Event b) {
        return (a.x < b.x || (a.x == b.x && a.tipe > b.tipe));
    });
    int answ = 0, cnt = 0, prev = -1;
    for (Event e : arr) {
        if (prev != -1 && cnt > 0) {
            answ += e.x - prev;
        }
        cnt += e.tipe;
        prev = e.x;
    }
    cout << answ;
}