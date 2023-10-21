#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int add() {

}

int del() {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> answ;
    map<int, pair<int, bool>> asks; // numOfAsk, firstEl, IsAdd?
    map<int, pair<int, bool>> mem; //firstEl, lenght, free?
    mem[0] = {n, true};
    for (int i = 0; i < m; i++) {
        int data; cin >> data; //asks[i + 1] = data;
        if (data > 0) {
            int firstFreeEl = 0;
            /*for (numOfLastAdd = asks.size(); numOfLastAdd >= 0; numOfLastAdd--) {
                if (asks[numOfLastAdd].second) {
                    break;
                }
            }*/
            while (!mem[firstFreeEl].second && firstFreeEl <= n) {
                firstFreeEl++;
            }
            if (firstFreeEl > n) {answ.push_back(-1);}
        } else {
            del();
        }
    }
    return 0;
}