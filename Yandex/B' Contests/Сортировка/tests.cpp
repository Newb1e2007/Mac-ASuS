#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

#define A

void solve();

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(1); // time(0));
  solve();
  return 0;
}

#ifdef A
  #define int long long
#endif

const int N = 3e5 + 500;
const int INF = 1e9 + 100;




vector<int> slow(vector<int> p){
  vector<int> ans;
  return ans;
}

vector<int> fast(vector<int> p){
  vector<int> ans;
  return ans;
}


void solve() {
  std::random_device rd;
  std::mt19937 g(rd());

  for(int i = 0; i < 100000; ++i){
    int n = random()%(N-1000);
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    shuffle(p.begin(), p.end(), g);
    auto f = fast(p);
    auto s = slow(p);
    
    if(f != s){
      for(int i = 0; i < f.size() && i < s.size(); ++i){
        cout << f[i] << ' ' << s[i] << '\n';
      }
      cout << '\n';
      for(int i = 0; i < p.size(); ++i){
        cout << p[i] << '\n';
      }
      cout << '\n';
      cout << '\n';
      cout << endl;
    }
  }
}