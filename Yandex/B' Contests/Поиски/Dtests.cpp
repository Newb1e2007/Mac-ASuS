#include <bits/stdc++.h>

#include <chrono>
#include <ctime>
#include <iomanip>
#include <random>

using namespace std;
using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 100000;
const int MAXR = 1000000;
const int MAXB = 1000000;
const int ITER_COUNT = 1000;


struct Party {
    ll number;
    ll votes;
    ll bribe;
    ll minVotesForWin;
    bool isAnswer = false;
};

vector<pair<ll, ll>> generate() {
    uniform_int_distribution<int> len_dist(1, MAXN);
    uniform_int_distribution<ll> r_dist(1, MAXR);
    uniform_int_distribution<ll> b_dist(-1, MAXB);
    uniform_int_distribution<ll> b_dist_2(1, MAXB);

    int len = len_dist(rng);
    vector<pair<ll, ll>> a(len);
    for (pair<ll, ll>& x : a) {
        x.first = r_dist(rng);
        x.second = b_dist(rng);
    }
    int count = 0;
    for (pair<ll, ll>& x : a) {
        if (x.second == -1) count++;
    }
    if (count == len) a[len_dist(rng) - 1].second = b_dist_2(rng);
    return a;
}

bool check(vector<Party> &arr, vector<ll> &suffSumm, ll n, ll p, ll x) {
    //cout << x << " in check\n";
    ll i = -1, j = n;
    ll count = 0;
    while (j - i > 1) {
        ll mid = (i + j) / 2;
        //cout << i << " " << j << " " << mid << " in 2 bp\n";
        if (arr[mid].votes >= x) {
            j = mid;
        } else {
            i = mid;
        }
    }
    if (j == p && p < n - 1) {
        j++;
    } else if (j == p && p == n - 1) {
        return true;
    }
    if (j <= p) {
        count = n - j - 1;
    } else {
        count = n - j;
    }
    if (suffSumm[j] - (x - 1) * (count) > x - arr[p].votes) {
        return false;
    } else {
        return true;
    }
}

void solve_smart(vector<pair<ll, ll>> a) {
    //cout << "\n";
    //for (pair<ll, ll> x : a) {
    //    cout << x.first << ' ' << x.second << "\n";
    //}
    //cout << "\n" << a.size() << "\n";
    ll n = a.size();
    vector <Party> arr(n);
    for (ll i = 0; i < n; i++) {
        arr[i].number = i + 1;
        arr[i].votes = a[i].first;
        arr[i].bribe = a[i].second;
    }
    sort(arr.begin(), arr.end(), [ & ](Party i, Party j) {
        return i.votes < j.votes;
    });
    vector <long long> suffSumm(n + 1);
    suffSumm[n] = 0;
    for (ll i = n - 1; i >= 0; i--) {
        suffSumm[i] = arr[i].votes + suffSumm[i + 1];
    }
    ll iters = 0;
    for (ll p = 0; p < n; p++) {
        iters++;
        //cout << iters << "\n";
        if (iters > 100000) {
            cout << "test failed\n";
            exit(0);
        }
        //cout << arr[p].votes << " " << arr[p].bribe << " bp start\n";
        if (arr[p].bribe == -1) {
            continue;
        }
        ll i = -1, j = suffSumm[0] + 1;
        while (j - i > 1) {
            ll mid = i + (j - i) / 2;
            //cout << i << " " << j << " " << mid << " in bp\n";
            if (check(arr, suffSumm, n, p, mid)) {
                j = mid;
            } else {
                i = mid;
            }
        }
        arr[p].minVotesForWin = j;
    }
    sort(arr.begin(), arr.end(), [ & ](Party i, Party j) {
        return (i.minVotesForWin - i.votes + i.bribe) < (j.minVotesForWin - j.votes + j.bribe);
    });
    ll x = 0;
    while (arr[x].bribe == -1) {
        x++;
    }

    ll currentMoney = arr[x].minVotesForWin - arr[x].votes;
    if (currentMoney < 0) {
        currentMoney = 0;
    }
    arr[x].isAnswer = true;
    arr[x].votes = max(arr[x].minVotesForWin, arr[x].votes);
    ll xVotes = arr[x].votes;
    //cout << currentMoney + arr[x].bribe << "\n" << arr[x].number << "\n";
    sort(arr.begin(), arr.end(), [ & ](Party i, Party j) {
        return i.votes > j.votes;
    });
    ll p = 0;
    cout << "before answer\n";
    while (currentMoney > 0) {
        if (arr[p].isAnswer) {
            p++;
        }
        if (p >= n) {
            p = 0;
        }
        if (arr[p].votes >= xVotes) {
            currentMoney -= (arr[p].votes - xVotes + 1);
            arr[p].votes = xVotes - 1;
            p++;
        } else {
            arr[p].votes -= currentMoney;
            if (arr[p].votes < 0) {
                currentMoney = abs(arr[p].votes);
                arr[p].votes = 0;
                p++;
            } else {
                currentMoney = 0;
            }
        }
    }
    cout << "+\n";
    sort(arr.begin(), arr.end(), [ & ](Party i, Party j) {
        return i.number < j.number;
    });
    /*for (ll i = 0; i < n; i++) {
        cout << arr[i].votes << " ";
    }*/
    return;
}

vector<int> solve_stupid(int n, vector<int> a) {
    sort(a.begin(), a.end());
    return a;
}

void test() {
    for (int i = 0; i < ITER_COUNT; ++i) {
        cout << "aboba\n";
        vector<pair<ll, ll>> a = generate();
        auto start = clock();
        //vector<int> res_smart = solve_smart(a.size(), a);
        solve_smart(a);
        auto end = clock();
        double time = (double)(end - start) / CLOCKS_PER_SEC;
        if (time > 1) {
            cout << "TEST " << i << " FAILED: TL\n";
            cout << fixed << setprecision(9) << time << " sec.\n";
            cout << a.size() << '\n';
            cout << "\n";
            exit(0);
        }
        /*vector<int> res_stupid = solve_stupid(a.size(), a);
        if (res_smart != res_stupid) {
            cout << "TEST " << i << " FAILED\n";
            cout << "INPUT:\n";
            cout << a.size() << '\n';
            for (int x : a) {
                cout << x << ' ';
            }
            cout << "\n\n";
            cout << "SMART:\n";
            for (int x : res_smart) {
                cout << x << ' ';
            }
            cout << "\n\n";
            cout << "STUPID:\n";
            for (int x : res_stupid) {
                cout << x << ' ';
            }
            cout << '\n';
            exit(0);
        }*/
    }
}

/*void solve_stdio() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }
    a = solve_smart(n, a);
    for (int x : a) {
        cout << x << ' ';
    }
    cout << '\n';
}*/

int main() {
    //cin.tie(nullptr)->sync_with_stdio(false);
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    // int t = 1;
    // // cin >> t;
    // while (t--) solve_stdio();

    test();
}