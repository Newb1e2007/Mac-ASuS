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
        int h, m, s; cin >> h >> m >> s;
        int h2, m2, s2; cin >> h2 >> m2 >> s2;
        int time1 = h*60*60 + m*60 + s;
        int time2 = h2*60*60 + m2*60 + s2;
        if (time1 >= time2) {
            Event a; a.x = 0; a.tipe = 1;
            Event b; b.x = time2; b.tipe = -1;
            Event c; c.x = time1; c.tipe = 1;
            Event d; d.x = 24*60*60; d.tipe = -1;
            arr.push_back(a);
            arr.push_back(b);
            arr.push_back(c);
            arr.push_back(d);
        } else {
            Event a; a.x = time1; a.tipe = 1;
            Event b; b.x = time2; b.tipe = -1;
            arr.push_back(a);
            arr.push_back(b);
        }
    }
    sort(arr.begin(), arr.end(), [ & ] (Event a, Event b) {
        return (a.x < b.x || (a.x == b.x && a.tipe > b.tipe));
    });

    int answ = 0, cnt = 0, prev = -1;
    for (Event e : arr) {
        if (cnt == n && prev != -1) {
            answ += e.x - prev;
        }
        cnt += e.tipe;
        prev = e.x;
    }
    cout << answ;
}

// |####|______|####
// ____|######|____
