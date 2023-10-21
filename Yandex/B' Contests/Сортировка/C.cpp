#include <iostream>
#define FOR(i, a, b) for (int i = a; i < b; i++)

using namespace std;

int main()
{
    int n, indMax;
    cin >> n;
    int arr[n];
    FOR(i, 0, n)
    {
        cin >> arr[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        indMax = i;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[indMax])
            {
                indMax = j;
            }
        }
        swap(arr[i], arr[indMax]);
    }

    FOR(i, 0, n)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
