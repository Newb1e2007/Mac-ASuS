/**
 *    author:  tourist
 *    created: 23.12.2023 09:38:31       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> l(n);
    for (int i = 0; i < n; i++) {
      cin >> l[i];
    }
    vector<long long> r(n);
    for (int i = 0; i < n; i++) {
      cin >> r[i];
    }
    vector<long long> c(n);
    for (int i = 0; i < n; i++) {
      cin >> c[i];
    }
    vector<pair<long long, int>> all;
    for (int i = 0; i < n; i++) {
      all.emplace_back(l[i], i);
      all.emplace_back(r[i], -i - 1);
    }
    sort(all.begin(), all.end());
    vector<long long> lens;
    multiset<long long> s;
    for (auto& p : all) {
      auto x = p.first;
      if (p.second >= 0) {
        s.insert(x);
      } else {
        assert(!s.empty());
        auto it = prev(s.end());
        lens.push_back(x - *it);
        s.erase(it);
      }
    }
    sort(lens.begin(), lens.end());
    sort(c.rbegin(), c.rend());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += lens[i] * c[i];
    }
    cout << ans << '\n';
  }
  return 0;
}