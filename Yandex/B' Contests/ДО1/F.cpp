#include <bits/stdc++.h>

using namespace std;

struct Node {
    int suff;
    int answ; // >= 0 всегда
    int pref;
    int len;
};

void merge(const Node& l, const Node& r) {
    Node res;
    res.len = l.len + r.len;
    if (l.suff + r.pref <= r.answ) {
        res.answ = l.answ + l.suff + r.pref + r.answ;
    } else {
        if (l.answ > r.answ) {
            res.answ = l.answ;
            res.pref = l.pref;
            res.suff = l.suff + r.pref + r.answ + r.pref;
        } else if (l.answ == r.answ) {
            res.answ = l.answ;
            if (l.pref > r.suff) {
                res.pref = l.pref;
                res.suff = l.suff + r.pref + r.answ + r.suff;
            } else {
                res.pref = l.suff + l.pref + l.answ + r.pref;
                res
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}