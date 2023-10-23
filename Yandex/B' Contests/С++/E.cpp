#include <bits/stdc++.h>

using namespace std;

struct Aquarium {
    int population;
    int timeNextBorn;
    int pos;  

    bool operator<(const Aquarium& other) const {
        if (timeNextBorn < other.timeNextBorn) {
            return true;
        } else if (timeNextBorn == other.timeNextBorn) {
            return pos < other.pos;
        } else {
            return false;
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    set<Aquarium> arr;
    for (int i = 0; i < n; i++) {
        int f; cin >> f;
        Aquarium a;
        a.pos = i; a.population = f; a.timeNextBorn = max(1000 - f, 1);
        arr.insert(a);
    }

    set<Aquarium>::iterator iter = arr.begin();
    int time = iter->timeNextBorn;
    int pos = iter->pos;
    int population = iter->population;
    if (pos > time) {
        cout << time;
        return 0;
    }
    arr.erase(iter);
    Aquarium a; a.pos = pos; a.population = ++population; a.timeNextBorn = time + max(1000 - a.population, 1);
    arr.insert(a);
    iter = arr.begin();

    while (abs(iter->pos - pos) <= iter->timeNextBorn - time) {
        pos = iter->pos;
        time = iter->timeNextBorn;
        population = iter->population;
        arr.erase(iter); 
        Aquarium a; a.pos = pos; a.population = ++population; a.timeNextBorn = time + max(1000 - a.population, 1);
        arr.insert(a);
        iter = arr.begin();
    }
    cout << iter->timeNextBorn;
    return 0;
}