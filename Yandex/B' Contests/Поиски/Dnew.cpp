#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Party {
    ll number;
    ll votes;
    ll bribe;
    ll minVotesForWin;
    bool isAnswer = false;
};

bool check(vector<Party> &arr, vector<ll> &suffSumm, ll n, ll p, ll x) {
    ll i = -1, j = n;
    ll count = 0;
    while (j - i > 1) {
        ll mid = (i + j) / 2;
        if (arr[mid].votes >= x) {
            j = mid;
        } else {
            i = mid;
        }
    }
    ll a = suffSumm[j];
    if (j <= p) {
        count = n - j - 1;
        a -= arr[p].votes;
    } else {
        count = n - j;
    }
    
    if (a - (x - 1) * (count) <= x - arr[p].votes) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    vector <Party> arr(n);
    for (ll i = 0; i < n; i++) {
        arr[i].number = i + 1;
        cin >> arr[i].votes >> arr[i].bribe;
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
        ll i = -1, j = suffSumm[0] + 1;
        while (j - i > 1) {
            ll mid = i + (j - i) / 2;
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
    //=====================================================================================================================================================
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
    cout << currentMoney + arr[x].bribe << "\n" << arr[x].number << "\n";
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
    for (ll i = 0; i < n; i++) {
        cout << arr[i].votes << " ";
    }
    return 0;
}   