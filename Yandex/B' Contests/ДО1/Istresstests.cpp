#include <bits/stdc++.h>

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int ITER_COUNT = 1000;

struct Test
{
    int n; 
    vector<int> arr;
    int max_el;
};

Test genTests() {
    uniform_int_distribution<int> n_size(3, 10);
    uniform_int_distribution<int> el_size(1, 10);
    int n = n_size(rng);
    Test newTest; newTest.n = n; 
    vector<int> arr(n);
    int max_el = 0;
    for (int i = 0; i < n; i++) {
        int a = el_size(rng);
        arr[i] = a;
        max_el = max(max_el, a);    
    }
    newTest.arr = arr;
    return newTest;
}

const int MAXN = 1e6;
vector < int > st(4*MAXN);
vector < int > arr;

void build(int v, int l, int r) {
    cout << "build 1\n";
    cout << v << '\n';
    if (r - l == 1) {
        st[v] = 0;
        return;
    }
    int mid = l + (r - l) / 2;
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid, r);   
    st[v] = st[2 * v + 1] + st[2 * v + 2];
    cout << "build 2\n";
}

void update(int i, int x, int v, int l, int r) {
    if (r - l == 1) {
        st[v] += x;
        return;
    }
    int mid = l + (r - l) / 2;
    if (i < mid) {
        update(i, x, 2 * v + 1, l, mid);
    } else {
        update(i, x, 2 * v + 2, mid, r);
    }
    st[v] = st[2 * v + 1] + st[2 * v + 2];
}

int get(int ql, int qr, int v, int l, int r) {
    if (qr <= l || r <= ql) return 0;
    if (ql <= l && r <= qr) return st[v];
    int mid = l + (r - l) / 2;
    return get(ql, qr, 2 * v + 1, l, mid) + get(ql, qr, 2 * v + 2, mid, r);
}

int slove_smart(Test newTest) {
    cout << "Im starting solve smart\n";
    int maxEl = newTest.max_el;
    int n = newTest.n;
    st.assign(4*MAXN, 0);
    cout << 'a' << '\n';
    vector<int> arr = newTest.arr;
    cout << 'c' << '\n';
    //cout << maxEl << '\n';
    build(0, 0, maxEl);
    cout << 'b' << '\n';
    unsigned long long answ = 0;
    cout << 1 << '\n';
    for (int i = 0; i < n; i++) {
        cout << 2 << '\n';
        for (int j = i - 1; j >= 0; j--) {
            cout << 3 << '\n';
            if (arr[j] > arr[i]) {
                update(arr[j], -1, 0, 0, maxEl);
                answ += (unsigned long long)get(arr[j], maxEl, 0, 0, maxEl);
            }
        }
        cout << 4 << '\n';
        for (int j = 0; j < i; j++) {
            cout << 5 << '\n';
            if (arr[j] > arr[i]) {
                update(arr[j], 1, 0, 0, maxEl);
            }
        }
        cout << 6 << '\n';
        update(arr[i], 1, 0, 0, maxEl);
        cout << 7 << '\n';
    }
    cout << "I finished solve smart\n";
    return answ;
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("output.txt", "w", stdout);
    cerr << "aboba\n";

    for (int i = 0; i < ITER_COUNT; i++) {
        cerr << "sds" << endl;
        cout << "before gen\n";
        Test newTest = genTests();
        cout << "===========\n";
        cout << newTest.n << '\n';
        for (int i = 0; i < newTest.n; i++) {
            cout << newTest.arr[i] << ' ';
        }
        //return 0;
        cout << "after gen\n";
        int answ = slove_smart(newTest);
        cerr << "TEST " << i + 1 << " PASSED!" << " answer is " << answ << '\n';
    }
    return 0;
}