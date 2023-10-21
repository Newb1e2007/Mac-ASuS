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
        return mn.front();
    }

    int max() {
        return mx.front();
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int m; cin >> m;
    vector<int> allK(m);
    for (int i = 0; i < m; i++) {
        cin >> allK[i];
    }
    for (int k : allK) {
        Smart_Deq sm;
        int l = 0, r = 0;
        sm.add(arr[0]);
        int maxLen = 1;
        pair<int, int> answ = {0, 0};
        while (r < n - 1) {
            r++;
            sm.add(arr[r]);
            while(sm.max() - sm.min() > k && l < r) {
                sm.pop();
                l++;
            }
            if (r - l + 1 > maxLen) {
                maxLen = r - l + 1;
                answ = {l, r};
            }
        }
        cout << answ.first + 1 << ' ' << answ.second + 1 << '\n';
    }
    return 0;
}