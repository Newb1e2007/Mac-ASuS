#include <bits/stdc++.h>

using namespace std;

using ull = unsigned  long long;

struct Sets {
    ull n;
    int m;
    map<int, set<ull>> sets; 
    unordered_map<ull, set<int>> el_set;
    Sets(ull n, int m): n(n), m(m) {
        /*for (int i = 0; i < m + 1; i++) {
            sets[i];
        }
        for (int i = 0; i < n; i++) {
            el_set[i];
        }*/
    } 

    void Add(ull e, int s) {
        sets[s].insert(e);
        el_set[e].insert(s);
        return;
    }

    void Delete(ull e, int s) {
        sets[s].erase(e);
        el_set[e].erase(s);
        return;
    }

    void Clear(int s) {
        for (const ull& el : sets[s]) {
            el_set[el].erase(s);
        }
        sets[s].clear();
        return;
    }

    void ListSet(int s) {
        if (sets[s].empty()) {
            cout << "-1\n";
        } else {
            for (const ull& el : sets[s]) {
                cout << el << ' ';
            }
            cout << '\n';
        }
        return;
    }

    void ListSetOf(ull e) {
        if (el_set[e].empty()) {
            cout << "-1\n";
        } else {
            for (const int& s : el_set[e]) {
                cout << s << ' ';
            }
            cout << '\n';
        }
        return;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, k;
    ull n;
    cin >> n >> m >> k;
    Sets sets(n, m);
    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        if (s == "ADD") {
            ull e;
            int s;
            cin >> e >> s;
            sets.Add(e, s);
        }
        if (s == "DELETE") {
            ull e;
            int s;
            cin >> e >> s;
            sets.Delete(e, s);
        }
        if (s == "CLEAR") {
            int s;
            cin >> s;
            sets.Clear(s);
        }
        if (s == "LISTSET") {
            int s;
            cin >> s;
            sets.ListSet(s);
        }
        if (s == "LISTSETSOF") {
            ull e;
            cin >> e;
            sets.ListSetOf(e);
        }
    }
    return 0;
}