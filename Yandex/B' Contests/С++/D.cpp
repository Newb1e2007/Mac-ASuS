#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int fP_s = 0, fP_e = n - 1, dE_e = -1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<pair<int, int>> answer;

    for (int target = 1; target <= n; target++) {
        if (dE_e >= 0 && fP_e - fP_s >= 0) {
            cout << "glob if\n";
            while (arr[dE_e] < target) {
                dE_e--;
            }
            if (arr[dE_e] == target) {
                answer.push_back(make_pair(2, 1));
                dE_e--;
            } else {
                bool isInF = false;
                int j = fP_s;
                for (j = fP_s; j <= fP_e; j++) {
                    if (arr[j] == target) {
                        isInF = true;
                        break;
                    }
                }
                if (isInF) {
                    cout << "aboba " << dE_e << ' ' << j << '\n';
                    answer.push_back(make_pair(1, j - fP_s - dE_e + 1));
                    answer.push_back(make_pair(2, 1));
                    dE_e = j - 1;
                    fP_s = j + 1;
                } else {
                    cout << 0;
                    return 0;
                }
            }
        } else if (dE_e >= 0) {
            cout << "glob else if\n";
            while (arr[dE_e] < target) {
                dE_e--;
            }
            if (arr[dE_e] == target) {
                answer.push_back(make_pair(2, 1));
                dE_e--;
            } else {
                cout << 0;
                return 0;
            }
        } else {
            cout << "glob else\n";
            bool isInF = false;
            int j = fP_s;
            for (j = fP_s; j <= fP_e; j++) {
                if (arr[j] == target) {
                    isInF = true;
                    break;
                }
            }
            if (isInF) {
                cout << "aboba " << dE_e << ' ' << j << '\n';
                answer.push_back(make_pair(1, j - fP_s - dE_e)); // dE_e = -1
                answer.push_back(make_pair(2, 1));
                dE_e = j - 1;
                fP_s = j + 1;
            } else {
                cout << 0;
                return 0;
            }
        }
    }

    cout << answer.size() << '\n';
    for (pair<int, int> el : answer) {
        cout << el.first << ' ' << el.second << '\n';
    }
    return 0;
}