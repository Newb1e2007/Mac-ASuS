#include <iostream>
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ll long long

using namespace std;

void mergeSort(ll arr[], ll buffer[], int left, int right, int middle)
{
    int i = left;
    int j = middle + 1;
    int ind = left;
    while (i < middle + 1 && j < right + 1)
    {
        if (arr[i] > arr[j])
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

void sort(ll arr[], ll buffer[], int left, int right)
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
    int n, k;
    cin >> n >> k;
    ll arr[n];
    ll buffer[n];
    FOR(i, 0, n)
    {
        ll el;
        cin >> el;
        arr[i] = el;
        buffer[i] = el;
    }
    sort(arr, buffer, 0, n - 1);
    cout << arr[k - 1];
    return 0;
}