#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct Party {
    ll number;
    ll votes;
    ll bribe;
    ll minVotesForWin = -1;
    bool isAnswer = false;
    ll diff;
};

bool compare(Party& i, Party& j) {
    ll diff2 = i.votes - j.votes;
    ll diff1 = j.votes - i.votes;
    if (diff2 < 0) diff2 = 0;
    if (diff1 < 0) diff1 = 0;
    //if (i.bribe == -1) diff1 = 1'000'000'000;
    //if (j.bribe == -1) diff2 = 1'000'000'000;
    i.diff = diff1 + i.bribe;
    j.diff = diff2 + j.bribe;
    return i.diff < j.diff;
}

bool check(vector<Party> arr, vector<ll> suffSumm, ll n, ll p, ll x) {
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

    sort(arr.begin(), arr.end(), compare);

    /*for (ll p = 0; p < n; p++) {
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
    }*/
    /*sort(arr.begin(), arr.end(), [ & ](Party i, Party j) {
        return (i.minVotesForWin - i.votes + i.bribe) < (j.minVotesForWin - j.votes + j.bribe);
    });*/
    ll x = 0;
    while (arr[x].bribe == -1) {
        x++;
    }
    arr[x].isAnswer = true;
    
    for (x = 0; x < n; x++) {
        if (arr[x].isAnswer) {
            break;
        }
    }
    sort(arr.begin(), arr.end(), [ & ](Party i, Party j) {
        return i.votes < j.votes;
    });
    ll i = -1, j = suffSumm[0] + 1;
    while (j - i > 1) {
        ll mid = i + (j - i) / 2;
        if (check(arr, suffSumm, n, x, mid)) {
            j = mid;
        } else {
            i = mid;
        }
    }
    arr[x].minVotesForWin = j; 
    cout << x << " " << j << "\n";
    /*while (arr[x + 1].diff == arr[x].diff) {
        x++;
        ll i = -1, j = suffSumm[0] + 1;
        while (j - i > 1) {
            ll mid = i + (j - i) / 2;
            if (check(arr, suffSumm, n, x, mid)) {
                j = mid;
            } else {
                i = mid;
            }
        }
        arr[x].minVotesForWin = j;
    }*/

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