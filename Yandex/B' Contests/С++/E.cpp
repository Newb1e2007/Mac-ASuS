#include <bits/stdc++.h>

using namespace std;

struct Aquarium {
    int population;
    int timeNextBorn;
    int num;  

    bool operator<(const Aquarium& other) const {
        return timeNextBorn < other.timeNextBorn;
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
        a.num = i; a.population = f; a.timeNextBorn = max(1000 - f, 1);
        arr.insert(a);
        //arr.insert({max(1000 - f, 1), i});
    }

    set<Aquarium>::iterator iter = arr.begin();
    int time = iter->timeNextBorn;
    int pos = iter->num;
    int population = iter->population;
    arr.erase(iter);
    Aquarium a; a.num = pos; a.population = population++; a.timeNextBorn = time + max(1000 - a.population, 1);
    arr.insert(a);
    iter = arr.begin();


    while (abs(iter->num - pos) <= iter->timeNextBorn - time) {
        pos = iter->num;
        time = iter->timeNextBorn;
        population = iter->population;
        arr.erase(iter);
        Aquarium a; a.num = pos; a.population = population++; a.timeNextBorn = time + max(1000 - a.population, 1);
        arr.insert(a);
        iter = arr.begin();
    }
    cout << iter->timeNextBorn;
    return 0;
}