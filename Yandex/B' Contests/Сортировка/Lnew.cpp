#include <bits/stdc++.h>

using namespace std;

void mergeSort(pair<char, int> arr[], pair<char, int> buffer[], int left, int right, int middle)
{
    int i = left;
    int j = middle + 1;
    int ind = left;
    while (i < middle + 1 && j < right + 1)
    {
        if (arr[i].second < arr[j].second)
        {
            buffer[ind] = arr[j];
            j++;
        }
        else
        {
            buffer[ind] = arr[i];
            i++;
        }
        ind++;
    }
    while (i < middle + 1)
    {
        buffer[ind] = arr[i];
        i++;
        ind++;
    }
    while (j < right + 1) {
        buffer[ind] = arr[j];
        j++;
        ind++;
    }
    for (int k = left; k < right + 1; k++)
    {
        arr[k] = buffer[k];
    }

    return;
}

void sort(pair<char, int> arr[], pair<char, int> buffer[], int left, int right)
{
    int middle = (right - left) / 2 + left;
    if (left < right)
    {
        sort(arr, buffer, left, middle);
        sort(arr, buffer, middle + 1, right);
        mergeSort(arr, buffer, left, right, middle);
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int size = s.length();
    map<char, int> letter_count;
    pair<char, int> letter_weight[26];
    pair<char, int> buffer[26];
    for (int i = 0; i < 26; i++) {
        int x;
        cin >> x;
        letter_weight[i] = make_pair(static_cast<char>(i + 97), x);
        buffer[i] = make_pair(static_cast<char>(i + 97), x);
    }  
    for (int i = 0; i < size; i++) {
        if (letter_count.count(s[i]) == 0){
            letter_count[s[i]] = 1;
        } else {
            letter_count[s[i]]++;
        }
    }
    sort(letter_weight, buffer, 0, 25);
    char answer[size + 1];
    int i = 0, j = size - 1;
    for (auto pair : letter_weight) {
        if (letter_count[pair.first] >= 2) {
            answer[i] = pair.first;
            answer[j] = pair.first;
            letter_count[pair.first] -= 2;
            i++;
            j--;
        }
    }
    for (auto pair : letter_weight) {
        while (letter_count[pair.first] > 0) {
            letter_count[pair.first]--;
            answer[i] = pair.first;
            i++;
        }
    }
    answer[size] = 0;
    cout << answer;
    return 0;
}