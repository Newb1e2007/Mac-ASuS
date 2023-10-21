#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> suffSum, vector<pair<int, vector<int> > > arr, int x, int ind) {
    int i = 0, j = arr.size(), mid;
    while (i < j) {
        mid = (i + j) / 2;
        if (arr[mid].first >= x) {
            j = mid;
        } else {
            i = mid;
        }
    }
    if (suffSum[j] -  (x - 1) * (arr.size() - j - 1) > x - arr[ind].first) {
        return false;
    } else {
        return true;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, vector<int> > > arr(n); // golos, vziatka, number 
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second[0];
        arr[i].second[1] = i;
    }
    sort(arr.begin(), arr.end(), [&](pair<int, vector<int> > i, pair<int, vector<int> > j) {return i.first < j.first;});
    vector<int> suffSumm(n + 1);
    suffSumm[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        suffSumm[i] = arr[i].first + suffSumm[i + 1];
    }
    vector<pair<int, pair<int, int> > > moneyForParty;
    
    for (int p = 0; p < n; p++) {
        if (arr[p].second[0] == -1) {
            moneyForParty[p].second.first = -1;
            continue;
        }
        int i = 0, j = suffSumm[0], mid;
        while (i < j) {
            mid = (i + j) / 2;
            if (check(suffSumm, arr, mid, p)) {
                j = mid;
            } else {
                i = mid;
            }
        }
        moneyForParty[p].first = mid;
        moneyForParty[p].second.first = arr[p].second[0];
        moneyForParty[p].second.second = arr[p].second[1];
    }
    sort(moneyForParty.begin(), moneyForParty.end(), [&](pair<int, pair<int, int> > i, pair<int, pair<int, int> > j) {return i.first + i.second.first < j.first + j.second.first;});
    int x = 0;
    while (moneyForParty[x].second.first == -1) {
        x++;
    }
    cout << moneyForParty[x].first + moneyForParty[x].second.first << "\n" << moneyForParty[x].second.second << "\n";
    vector<int> answer(n);
    int i = 0, j = arr.size(), mid;
    while (i < j) {
        mid = (i + j) / 2;
        if (arr[mid].first >= moneyForParty[x].first) {
            j = mid;
        } else {
            i = mid;
        }
    }
    int minMin = moneyForParty[x].first;
    sort(arr.begin(), arr.end(), [&](pair<int, pair<int, int> > i, pair<int, pair<int, int> > j) {return i.first + i.second.first < j.first + j.second.first;});
    while (moneyForParty[x ].first > 0) {
        for (int k = 1; k < n - 1; k++) {
            if (arr[k].first > 0) {
                moneyForParty[x].first -= 
            }
        }
    }
}