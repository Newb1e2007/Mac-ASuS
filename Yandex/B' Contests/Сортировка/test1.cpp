#include <bits/stdc++.h>

using namespace std;

random_device rd;
mt19937 gen(rd());

string generateRandomString(int n) {
    // Создаем генератор случайных чисел
    uniform_int_distribution<int> dis('a', 'z'); // Диапазон букв от 'a' до 'z'

    // Генерируем случайные буквы и добавляем их к строке
    string result;
    for (int i = 0; i < n; ++i) {
        char randomChar = static_cast<char>(dis(gen));
        result += randomChar + ' ';
    }

    return result;
}

int main() {
    uniform_int_distribution<int> dis(0, 100000);
    freopen("output.txt", "w", stdout);
    int size, n;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        size = dis(gen);
        s = generateRandomString(size);
        map<char, int> letter_count;
        for (int i = 0; i < size; i++) {
            if (letter_count.count(s[i]) == 0){
                letter_count[s[i]] = 1;
            } else {
                letter_count[s[i]]++;
            }
        }
        int summ = 0;
        for (auto pair : letter_count) {
            summ += pair.second;
        }
        if (size == summ) {
            cout << true << "\n";
        } else {
            cout << false << "\n";
        }
    }
    return 0;
}