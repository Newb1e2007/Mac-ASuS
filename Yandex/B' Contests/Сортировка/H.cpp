#include <iostream>
#include <random>
#define FOR(i, a, b) for (int i = a; i < b; i++)

using namespace std;

random_device rd;
mt19937 gen(rd());

int genRandomPivot(int &left, int &right) {
    uniform_int_distribution<int> distribution(left, right);
    return distribution(gen);
}

inline void swap(int &a, int &b) {
    int temp = b;
    b = a;
    a = temp;
}

void divide(int arr[], int left, int right, int pivot, int &lFlag, int &rFlag) {
    int i = left;

    while (i <= rFlag) {
        if (arr[i] < pivot) {
            swap(arr[i++], arr[lFlag++]);
        } else if (arr[i] > pivot) {
            swap(arr[i], arr[rFlag]);
            rFlag--;
        } else {
            i++;
        }
    }
}

void qSort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[genRandomPivot(left, right)];
        int lFlag = left, rFlag = right;
        divide(arr, left, right, pivot, lFlag, rFlag); 
        qSort(arr, left, lFlag - 1);
        qSort(arr, rFlag, right);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    FOR(i, 0, n) {
        cin >> arr[i];
    }
    qSort(arr, 0, n - 1);
    FOR(i, 0, n) {
        cout << arr[i] << " ";
    }
    return 0;
}