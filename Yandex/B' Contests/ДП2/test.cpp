#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> arr {1, 2, 3, 4, 5, 10};
    int i = upper_bound(arr.begin(), arr.end(), 10) - arr.begin();
    cout << i;
}