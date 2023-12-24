#include <bits/stdc++.h>

using namespace std;

int main() {
    long long res = 1;
    for (int i = 30; i >= 16; i--) {
        res *= i;
    }
    for (int i = 1; i <= 15; i++) {
        res /= i;
    }
    cout << res;
}