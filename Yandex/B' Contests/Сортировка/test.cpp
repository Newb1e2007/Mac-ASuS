#include <bits/stdc++.h>

using namespace std;

int *generateRandomArray(int (&result)[], int length) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, numeric_limits<int>::max());

    for (int i = 0; i < length; ++i) {
        result[i] = dis(gen);
    }

    return result;
}
namespace mergeSort {
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
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("output.txt", "w", stdout);
    //string s;
    //cin >> s;
    //int size = s.length();
    //map<char, int> letter_count;
    int n;
    cin >> n;
    for (int j = 0; j < n; j++) {
        int a[26];
        pair<char, int> letter_weight[26];
        pair<char, int> buffer[26];
        generateRandomArray(a, 26);
        for (int i = 0; i < 26; i++) {
            letter_weight[i] = make_pair(static_cast<char>(i + 97), a[i]);
            buffer[i] = make_pair(static_cast<char>(i + 97), a[i]);
            //cout << letter_weight[i].first << " " << letter_weight[i].second << ", ";
        }
        //cout << "\n";
        /*for (int i = 0; i < 26; i++) {
            int x;
            cin >> x;
            letter_weight[i] = make_pair(static_cast<char>(i + 97), x);
            buffer[i] = make_pair(static_cast<char>(i + 97), x);
        }*/
        /*for (int i = 0; i < size; i++) {
            if (letter_count.count(s[i]) == 0){
                letter_count[s[i]] = 1;
            } else {
                letter_count[s[i]]++;
            }
        }*/
        mergeSort::sort(letter_weight, buffer, 0, 25);
        std::sort(a, a + 26, greater<int>());
        bool isRight = true;
        for (int i = 0; i < 26; i++) {
            //cout << letter_weight[i].first << " " << letter_weight[i].second << ", ";
            if (letter_weight[i].second != a[i]) {
                isRight = false;
            }
        }
        cout << isRight << "\n";
        //cout << "\n\n";
    }
    return 0;
}