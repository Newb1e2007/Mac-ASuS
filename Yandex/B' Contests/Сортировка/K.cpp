#include <iostream>
#include <string>
#include <algorithm>
#define FOR(i, a, b) for (int i = a; i < b; i++)

using namespace std;

void mergeSort(char arr[], char buffer[], int left, int right, int middle)
{
    int i = left;
    int j = middle + 1;
    int ind = left;
    while (i < middle + 1 && j < right + 1)
    {
        if (arr[i] < arr[j])
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

void sort(char arr[], char buffer[], int left, int right)
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
    string a, b;
    getline(cin, a);
    getline(cin, b);
    int size = a.length();
    char arr1[size], arr2[size], buffer1[size], buffer2[size];
    FOR(i, 0, size) {
        arr1[i] = a[i];
        arr2[i] = b[i];
        buffer1[i] = a[i];
        buffer2[i] = b[i];
    }
    sort(arr1, buffer1, 0, size - 1);
    sort(arr2, buffer2, 0, size - 1);
    if(equal(arr1, arr1 + size, arr2)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}