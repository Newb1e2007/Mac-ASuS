#include <bits/stdc++.h>

#include <chrono>
#include <random>

using namespace std;
using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 100000;
const int MAXR = 1000000;
const int MAXB = 1000000;
const int ITER_COUNT = 100;

struct Party {
    ll number;
    ll votes;
    ll bribe;
    ll minVotesForWin;
    bool isAnswer = false;
};

bool compare(vector<Party> &a, vector<Party> &b) {
    for (ll i = 0; i < a.size(); i++) {
        if (a[i].votes != b[i].votes) {
            return false;
        }
    }
    return true;
}

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

vector<Party> solve_smart(vector<pair<ll, ll>> &a) {
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
    sort(arr.begin(), arr.end(), [ & ](Party i, Party j) {
        return i.number < j.number;
    });
    /*for (ll i = 0; i < n; i++) {
        cout << arr[i].votes << " ";
    }*/
    return arr;
}

vector<Party> solve_stupid(vector<pair<ll, ll>> &a) {
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

    for (ll p = 0; p < n; p++) {
        if (arr[p].bribe == -1) {
            continue;
        }
        for (ll i = 0; i <= suffSumm[0]; i++) {
            if (check(arr, suffSumm, n, p, i)) {
                arr[p].minVotesForWin = i;
                break;
            }
        }
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
    sort(arr.begin(), arr.end(), [ & ](Party i, Party j) {
        return i.number < j.number;
    });
    return arr;
}

void test() {
    for (int i = 0; i < ITER_COUNT; ++i) {
        cout << "new test " << i << '\n';
        vector<pair<ll, ll>> a = generate();
        vector<Party> res_smart = solve_smart(a);
        vector<Party> res_stupid = solve_stupid(a);
        if (!compare(res_smart, res_stupid)) {
            cout << "TEST " << i << " FAILED\n";
            cout << "INPUT:\n";
            cout << a.size() << '\n';
            for (pair<ll, ll> x : a) {
                cout << x.first << ' ' << x.second << ", ";
            }
            cout << "\n\n";
            cout << "SMART:\n";
            for (Party x : res_smart) {
                cout << x.votes << ' ';
            }
            cout << "\n\n";
            cout << "STUPID:\n";
            for (Party x : res_stupid) {
                cout << x.votes << ' ';
            }
            cout << '\n';
            exit(0);
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    //freopen("output.txt", "w", stdout);

    // int t = 1;
    // // cin >> t;
    // while (t--) solve_stdio();

    test();
}