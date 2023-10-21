#include <iostream>
#define FOR(i, a, b) for (int i = a; i < b; i++)
 
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    FOR(i, 0, n) {
        cin >> arr[i];
    }

    FOR(i, 0, n) {
        FOR(j, 0, n - 1) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    FOR(i, 0, n) {
        cout << arr[i] << " ";
    }
    return 0;
}