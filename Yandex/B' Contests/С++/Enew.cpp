#include <bits/stdc++.h>

using namespace std;

bool check(vector<pair<int, int>>& arr, int time) {
    sort(arr.begin(), arr.end(), [ & ](pair<int, int> i, pair<int,int> j){return i.first > j.first;});
    int pos = arr[0].second;
    while ()
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first; 
        arr[i].second = i;
    }
    int l = 1, r = 2007;
    while(r - l > 1) {
        int mid = l + (r - l) / 2;
        if(check) {

        }
    }
}