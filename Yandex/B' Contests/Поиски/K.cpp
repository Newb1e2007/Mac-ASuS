#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);

    int l = 0, r = n - 1, mid; 
    
    while (r - l > 2) {
        mid = l + (r - l) / 2;
        if (arr[mid] == 0) {
            cout << "? " << mid + 1 << endl;
            fflush(stdout);
            cin >> arr[mid];
        }
        if (arr[mid - 1] == 0) {
            cout << "? " << mid << endl;
            fflush(stdout);
            cin >> arr[mid - 1];
        }
        if ((mid - l + 1) % 2 == 0) {
            if (arr[mid - 1] == arr[mid]) {
                l = mid - 1;
            } else {
                r = mid - 1;
            }
        } else {
            if (arr[mid - 1] == arr[mid]) {
                r = mid;
            } else {
                l = mid;
            }
        }
    }

    mid = l + (r - l) / 2;
    if (arr[mid] == 0) {
        cout << "? " << mid + 1 << endl;
        fflush(stdout);
        cin >> arr[mid];
    }
    if (arr[l] == 0) {
        cout << "? " << l + 1 << endl;
        fflush(stdout);
        cin >> arr[l];
    }
    if (arr[r] == 0) {
        cout << "? " << r + 1 << endl;
        fflush(stdout);
        cin >> arr[r];
    }
    if (arr[mid] == arr[l]) {
        cout << "! " << arr[r] << endl;
    } else {
        cout << "! " << arr[l] << endl;
    }
    return 0;
}