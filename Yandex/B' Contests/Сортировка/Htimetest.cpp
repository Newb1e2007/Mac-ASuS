#include <iostream>
#include <random>
#include <chrono>
#include <ctime>
#include <cstdlib>
#define FOR(i, a, b) for (int i = a; i < b; i++)

using namespace std;

random_device rd;
mt19937 gen(rd());

std::vector<int> generateRandomVector(int n) {
    std::vector<int> result;
    
    // Инициализация генератора случайных чисел с использованием текущего времени
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    for (int i = 0; i < n; ++i) {
        // Генерация случайного числа в диапазоне от 1 до 10^9
        int randomNumber = 1 + (std::rand() % 1000000000);
        result.push_back(randomNumber);
    }
    
    return result;
}

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
    vector<int> array;
    array = generateRandomVector(n);
    for (int i = 0; i < n; i++) {
        arr[i] = array[i];
    }
    auto start = std::chrono::high_resolution_clock::now();
    qSort(arr, 0, n - 1);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Время выполнения: " << duration.count() << " микросекунд" << std::endl;
    //FOR(i, 0, n) {
    //    cout << arr[i] << " ";
    //}
    return 0;
}