#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll nod(ll a, ll b) {
    if (a % b == 0)
        return b;
    if (b % a == 0)
        return a;
    if (a > b)
        return nod(a%b, b);
    return nod(a, b%a);
}

/*struct smart_deq {
    deque<int> deq;
    queue<int> q; //nod

    void add(int x) {
        q.push(x);
        //q.push(nod(q.front(), x));
        while(!deq.empty() && deq.back() > x) {
            deq.pop_back();
        }
        deq.push_back(x);
    }

    void del() {
        if (deq.front() == q.front()) {
            deq.pop_front();
        }
        q.pop();
    }

    void min() {
        cout << deq.front() << '\n';
        //return deq.front();
    }
};*/

struct window {

};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {cin >> arr[i];}

    ll currNod = arr[k - 1];
    vector<ll> nods(k);
    for (int i = k - 2; i >= 0; i--) {
        nods[i] = 
        currNod = nod(currNod, arr[i]);
    }


}