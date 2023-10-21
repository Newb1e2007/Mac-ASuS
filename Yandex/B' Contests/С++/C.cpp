#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> population(n);
    for (int i = 0; i < n; i++) {
        cin >> population[i];
    }
    sort(population.begin(), population.end(), [ & ](int i, int j) {
        return i > j;
    });
    cout << 1000 - min(population[0], population[1]) + 1;
    return 0;
}