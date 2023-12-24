#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
using ll = long long;

struct Event
{
    int x;
    int type;
    ll c;
    int num;
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<Event> events;
    for (int i = 0; i < n; i++) {
        int s, t; ll c; cin >> s >> t >> c;
        Event e;
        e.num = i;
        e.x = s;
        e.type = 1;
        e.c = c;
        events.push_back(e);
        e.x = s + t;
        e.type = -1;
        events.push_back(e);        
    }
    sort(events.begin(), events.end(), [ & ](Event i, Event j){
        if (i.x == j.x) return i.type < j.type;
        return i.x < j.x;
    });
    
    int lastCl = 0;
    vector<int> last(n);
    int i = 1;
    vector<ll> dp(n + 1);
    for (Event e : events) {
        if (e.type == -1) {
            dp[i] = max(dp[last[e.num]] + e.c, dp[i - 1]);
            lastCl = i;
            i++;
        }
        if (e.type == 1) {
            last[e.num] = lastCl;
        }
    }
    cout << dp[n];

    return 0;
}