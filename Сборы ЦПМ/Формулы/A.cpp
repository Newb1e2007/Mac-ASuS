#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b; cin >> a >> b;
    cout << a / b * b << '\n' << (a + b - 1) / b * b;
    return 0;
}