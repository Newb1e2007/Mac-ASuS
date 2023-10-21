#include <iostream>
#include <vector>

#define FOR(i, a, b) for (int i = a; i < b; i++)

using namespace std;

int main()
{
    int n, minEl = 0, maxEl = 0;
    cin >> n;
    vector<int> arr;
    FOR(i, 0, n)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    FOR(i, 0, n)
    {
        minEl = min(minEl, arr[i]);
        maxEl = max(maxEl, arr[i]);
    }
    vector<int> helpArr (maxEl - minEl + 1, 0);
    for (int i = 0; i < n; i++) {
        helpArr[arr[i] - minEl]++;
    }

    FOR(i, 0, maxEl - minEl + 1)
    {
        while (helpArr[i] > 0) {
            cout << i + minEl << " ";
            helpArr[i]--;
        }
    }
    return 0;
}