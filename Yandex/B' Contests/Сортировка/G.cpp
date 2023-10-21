#include <iostream>
#include <vector>

using namespace std;

long long mergeTwoArr(int buffer[], int transposition[], int leftInd, int rightInd, int midInd) {
    long long count = 0;
    int i = leftInd;
    int j = midInd + 1;
    int ind = leftInd;
    while (i < midInd + 1 && j < rightInd + 1) {
        if (transposition[i] > transposition[j]) {
            count += midInd + 1 - i;
            buffer[ind] = transposition[j];
            j++;
        } else {
            buffer[ind] = transposition[i];
            i++;
        }
        ind++;
    }
    while (i < midInd + 1) {
        buffer[ind] = transposition[i];
        i++;
        ind++;
    }
    for (int k = leftInd; k < rightInd + 1; k++) {
        transposition[k] = buffer[k];
    }

    return count;
}

long long sort(int buffer[], int transposition[], int leftInd, int rightInd) {
    long long fCount = 0;
    if (leftInd < rightInd) {
        int midInd = leftInd + ((rightInd - leftInd) / 2);
        fCount += sort(buffer, transposition, leftInd, midInd);
        fCount += sort(buffer, transposition, midInd + 1, rightInd);
        fCount += mergeTwoArr(buffer, transposition, leftInd, rightInd, midInd);
    }
    return fCount;
}

int main() {
    int n;
    cin >> n;
    int buffer[n];
    int transposition[n];

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        transposition[i] = p;
        buffer[i] = p;
    }

    cout << sort(buffer, transposition, 0, n - 1) << "\n";
    for (int i = 0; i < n; i++) {
        cout << transposition[i] << " ";
    }
    return 0;
}