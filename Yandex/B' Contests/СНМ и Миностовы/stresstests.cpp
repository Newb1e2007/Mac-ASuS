#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<int> sz, p;
vector<ll> summ;
vector<bool> alive;

ll answ = 0;

int getRoot(int v) {
    if (v == p[v]) return v;
    return p[v] = getRoot(p[v]);
}

void unite(int a, int b) {
    a = getRoot(a);
    b = getRoot(b);
    if (a == b) {
        return;
    }
    if (sz[a] > sz[b]) swap(a, b);
    p[a] = b;
    sz[b] += sz[a];
    summ[b] += summ[a];
    answ = max(answ, summ[b]);
}

vector<ll> solveSmart(  ) {
    int n; cin >> n;
    alive.resize(n);
    sz.resize(n, 1);
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    summ.resize(n);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> ord(n);
    for (int i = 0 ; i < n; i++) {
        cin >> ord[i];
        ord[i]--;
    }
    reverse(ord.begin(), ord.end());
    vector<ll> answer;
    answer.reserve(n);  
    for (auto ask : ord) {
        answer.push_back(answ);
        alive[ask] = true;
        summ[ask] = arr[ask];
        answ = max(answ, summ[ask]);
        if (ask < n - 1 && alive[ask + 1]) unite(ask, ask+1);
        if (ask > 0 && alive[ask - 1]) unite(ask, ask - 1);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    

}