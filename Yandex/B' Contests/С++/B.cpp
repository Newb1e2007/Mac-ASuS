#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    deque<int> qStart, qEnd;
    for (int i = 0; i < n; i++) {
        char m;
        cin >> m;
        if (m == '+') {
            int gn;
            cin >> gn;
            qEnd.push_back(gn);
            if (qEnd.size() > qStart.size()) {
                qStart.push_back(qEnd.front());
                qEnd.pop_front();
            }
        }
        if (m == '-') {
            cout << qStart.front() << '\n';
            qStart.pop_front();
            if (qEnd.size() > qStart.size()) {
                qStart.push_back(qEnd.front());
                qEnd.pop_front();
            }
        }
        if (m == '*') {
            int gn;
            cin >> gn;
            if (qStart.size() <= qEnd.size()) {
                qStart.push_back(gn);
            } else {
                qEnd.push_front(gn);
            }
        }
    }
    return 0;
}