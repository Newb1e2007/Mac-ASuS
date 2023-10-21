#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n1, n2, n3, n4; cin >> n1;
    vector<pair<int, int>> arr(n1);
    for (int i = 0; i < n1; i++) {int a; cin >> a; arr[i] = {a, 1};}
    cin >> n2;
    for (int i = 0; i < n2; i++) {int a; cin >> a; arr.push_back({a, 2});}
    cin >> n3;
    for (int i = 0; i < n3; i++) {int a; cin >> a; arr.push_back({a, 3});}
    cin >> n4;
    for (int i = 0; i < n4; i++) {int a; cin >> a; arr.push_back({a, 4});}
    sort(arr.begin(), arr.end(), [ & ] (pair<int, int> i, pair<int, int> j) {return i.first < j.first;});

    pair<int, int> currAnsw;
    int minDiff = arr.back().first - arr[0].first;
    map<int, int> kit; 
    kit[1] = 0; kit[2] = 0; kit[3] = 0; kit[4] = 0;
    int l = 0, r = 0;

    while (arr[l + 1].second == arr[l].second) {
        l++;
    }
    kit[arr[l].second] = 1;
    r = l;

    while (r < n1 + n2 + n3 + n4 - 1) {
        r++;
        kit[arr[r].second]++;
        if (kit[1] && kit[2] && kit[3] && kit[4]) {
            while (kit[arr[l].second] > 1) {
                kit[arr[l].second]--;
                l++;
            }
            if (arr[r].first - arr[l].first < minDiff) {
                minDiff = arr[r].first - arr[l].first;
                currAnsw = {l, r};
            }
            while (arr[l + 1].second == arr[l].second) {
                l++;
                kit[arr[l].second]--;
            }
        }
    }
    int ind = currAnsw.first;
    while (arr[ind].second != 1) {
        ind++;
    }
    cout << arr[ind].first << ' ';
    ind = currAnsw.first;
    while (arr[ind].second != 2) {
        ind++;
    }
    cout << arr[ind].first << ' ';
    ind = currAnsw.first;
    while (arr[ind].second != 3) {
        ind++;
    }
    cout << arr[ind].first << ' ';
    ind = currAnsw.first;
    while (arr[ind].second != 4) {
        ind++;
    }
    cout << arr[ind].first;

    return 0;
}