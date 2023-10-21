#include <iostream>
#define FOR(i, a, b) for (int i = a; i < b; i++)
 
using namespace std;

int main() {
    int n, ind;
    cin >> n;
    int arr[n];
    FOR(i, 0, n) {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            } else {
                break;
            }
        }
    }
    FOR(i, 0, n) {
        cout << arr[i] << " ";
    }
    return 0;
}
