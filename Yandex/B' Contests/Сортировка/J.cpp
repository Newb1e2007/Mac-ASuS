#include <iostream>
#define FOR(i, a, b) for (int i = a; i < b; i++)

using namespace std;

void mergeSort(pair<int, int> arr[], pair<int, int> buffer[], int left, int right, int middle)
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
        else if (arr[i].second == arr[j].second) {
            if (arr[i].first > arr[j].first) {
                buffer[ind] = arr[j];
                j++;
            } else {
                buffer[ind] = arr[i];
                i++;
            }
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

void sort(pair<int, int> arr[], pair<int, int> buffer[], int left, int right)
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
    int n;
    cin >> n;
    pair<int, int> arr[n], buffer[n];
    FOR(i, 0, n) {
        int a, b;
        cin >> a >> b;
        arr[i] = make_pair(a, b);
        buffer[i] = make_pair(a, b);
    }
    sort(arr, buffer, 0, n - 1);
    FOR(i, 0, n) {
        cout << arr[i].first << " " << arr[i].second << "\n";
    }
    return 0;
}