#include <bits/stdc++.h>

using namespace std;

struct Smart_Deq {
    deque<int> mn;
    deque<int> mx;
    queue<int> q;

    void add(int x) {
        q.push(x);
        while(!mn.empty() && mn.back() > x) {
            mn.pop_back();
        }
        mn.push_back(x);
        while(!mx.empty() && mx.back() < x) {
            mx.pop_back();
        }
        mx.push_back(x);
    }

    void pop() {
        if (mn.front() == q.front()) {
            mn.pop_front();
        }
        if (mx.front() == q.front()) {
            mx.pop_front();
        }
        q.pop();
    }

    int min() {
        //cout << mn.front() << '\n';
        return mn.front();
    }

    int max() {
        //cout << mx.front() << '\n';
        return mx.front();
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
    Smart_Deq sd;
    for (int i = 0; i < k; i++) {
        sd.add(arr[i]);
    }
    cout << sd.max() << ' ';
    for (int i = 1; i < n - k + 1; i++) {
        sd.pop(); sd.add(arr[i + k - 1]);
        cout << sd.max() << ' ';
    }

    return 0;
}