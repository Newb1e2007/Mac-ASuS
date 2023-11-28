#include <bits/stdc++.h>

using namespace std;

struct Node {
    int summ = 0;
};

Node resV; 

int MAXN = 1e5;
vector<Node> st(4*MAXN);
vector<int> arr;

Node merge(const Node& l, const Node& r) {
    Node res;
    res.summ = l.summ + r.summ;
    return res;
}

void build (int v, int l, int r) {
    if (r - l == 1) {
        Node curV;
        curV.summ = arr[l];
        st[v] = curV;
        return;
    }
    int mid = l + (r - l) / 2;
    build(2*v + 1, l, mid);
    build(2*v + 2, mid, r);
    st[v] = merge(st[2*v + 1], st[2*v + 2]);
}

void update(int i, int x, int v, int l, int r) {
    if (r - l == 1) {
        Node curV;
        curV.summ = x;
        st[v] = curV;
        return;
    }
    int mid = l + (r - l) / 2;
    if (i < mid) {
        update(i, x, 2*v + 1, l, mid);
    } else {
        update(i, x, 2*v + 2, mid, r);
    }
    st[v] = merge(st[2*v + 1], st[2*v + 2]);
}

/*Node get(int s, int v, int l, int r) {
    if (st[v].summ == s) {
        return true;
    }
    if (ql <= l && r <= qr) return st[v];
    int mid = l + (r - l) / 2;
    return merge(get(ql, qr, 2*v + 1, l, mid), get(ql, qr, 2*v + 2, mid, r));
}*/

Node get(int s, int v, int l, int r) {
    if (st[v].summ == s) {
        return resV;
    } 
    if (st[v].summ > s) {
        int mid = l + (r - l) / 2;
        if (get(s, 2*v + 1, l, mid).summ == -1 || get(s, 2*v + 2, mid, r).summ == -1) {
            return resV;
        } else {
            return merge(get(s, 2*v + 1, l, mid), get(s, 2*v + 2, mid, r));
        }
    } else {
        return st[v];
    }
}

void solve() {
    resV.summ = -1;
    int n, q; cin >> n >> q;
    arr.resize(n);
    int summ = 0;
    for (int i = 0; i< n; i++) {
        cin >> arr[i];
        summ += arr[i];
    }    
    //build(0, 0, n);
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        if (t == 1) {
            bool flag = false;
            int s; cin >> s;
            int l = 0, r = n - 1;
            /*if (summ == s) {
                cout << "YES\n";
                return;
            }*/
            int curSumm = summ, i = 0;
            while (curSumm >= s) {
                if (curSumm == s) {
                    flag = true;
                    break;
                }
                if (i == 0) {
                    curSumm -= arr[l];
                    l++;
                } else {
                    curSumm -= arr[r];
                    r--;
                }
                i = (i + 1) % 2;
            }
            if (flag) {
                cout << "YES\n";
            } else 
                cout << "NO\n";
        } else {
            int i, x; cin >> i >> x;
            //update(i - 1, x, 0, 0, n);
            arr[i - 1] = x;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
    
    return 0;
}
