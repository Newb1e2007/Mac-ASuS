#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int firstRoom;
    cin >> firstRoom;
    int n = 1;
    bool fA = false;
    while(!fA) {
        n *= 2;
        vector<int> currRooms;
        currRooms.reserve(n);
        currRooms.push_back(firstRoom);
        for (int i = 1; i < n; i++) {
            cout << 'R' << endl;
            int room;
            cin >> room;
            currRooms.push_back(room);
        }
        cout << 'S' << endl;
        for (int i = n - 1; i > 0; i--) {
            cout << 'L' << endl;
            int room;
            cin >> room;
            if (room != currRooms[i - 1]) {
                cout << n - i << endl;
                return 0;
            }
        }
    }

    return 0;
}