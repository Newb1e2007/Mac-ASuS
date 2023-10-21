#include <iostream>
#include <vector>
#include <string>
#define FOR(i, a, b) for (int i = a; i < b; i++)

using namespace std;

void mergeSort(string arr[], string buffer[], int left, int right, int middle)
{
    int i = left;
    int j = middle + 1;
    int ind = left;
    while (i < middle + 1 && j < right + 1)
    {
        if ((arr[j] + arr[i]).compare((arr[i] + arr[j])) > 0)
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

void sort(string arr[], string buffer[], int left, int right)
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
    vector<string> p, b;
    string x;
    int n;
    cin >> n;
    /*while (cin >> x) {
        p.push_back(x);
        b.push_back(x);
    }*/
    FOR(i, 0, n) {
        cin >> x;
        p.push_back(x);
        b.push_back(x);
    }
    string arr[p.size()], buffer[p.size()];
    FOR(i, 0, p.size()) {
        arr[i] = p[i];
        buffer[i] = b[i];
    }
    sort(arr, buffer, 0, p.size() - 1);
    FOR(i, 0, p.size()) {
        cout << arr[i];
    }
    return 0;
}