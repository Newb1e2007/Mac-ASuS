#include <bits/stdc++.h>
#define ld long double

using namespace std;

struct treasure {
    int num;
    ld v;
    ld w;
    ld currentC;
};

void sortStruct(vector<treasure> &arr, ld t, int n) {
    for (int i = 0; i < n; i++) {
        arr[i].currentC = arr[i].v - t*arr[i].w;
    }
    sort(arr.begin(), arr.end(), [&](treasure i, treasure j){return i.currentC > j.currentC;});
    return;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<treasure> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i].num = i + 1;
        cin >> arr[i].v >> arr[i].w;
    }
    ld l = 0.000001, r = 1000000, mid;
    for (int epoch = 0; epoch < 100; epoch++) {
        mid = (l + r) / 2;
        sortStruct(arr, mid, n);
        ld summ = 0.0;
        for (int i = 0; i < k; i++) {
            summ += arr[i].currentC;
        }
        if (summ >= 0) {
            l = mid;
        } else {
            r = mid;
        }
    }
    for (int i = 0; i < k; i++) {
        cout << arr[i].num << " ";
    }
    return 0;
}