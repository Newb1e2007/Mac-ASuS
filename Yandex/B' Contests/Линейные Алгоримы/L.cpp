#include <bits/stdc++.h>

using namespace std;

struct smart_deq {
    deque<int> deq;
    queue<int> q;

    void add(int x) {
        q.push(x);
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
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    smart_deq sd;
    for (int i = 0; i < k; i++) {
        sd.add(arr[i]);
    }
    sd.min();
    for (int i = 1; i < n - k + 1; i++) {
        sd.del(); sd.add(arr[i + k - 1]);
        sd.min();
    }

    return 0;
}