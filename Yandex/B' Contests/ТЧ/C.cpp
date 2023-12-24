#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b; cin >> a >> b;
    vector<bool> primes(b + 1, true);
    primes[0] = false;
    primes[1] = false;
    for (int i = 2; i <= b; i++) {
        if (primes[i]) {
            for (int j = 2 * i; j <= b; j += i) {
                primes[j] = false;
            }
        }
    }
    for (int i = a; i <= b; i++) {
        if (primes[i]) cout << i << ' ';
    }
}