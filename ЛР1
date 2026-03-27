#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    const int max = 8;
    char a[9]; //0-8
    char b[9]; //0-8
    int len_a;
    int len_b;

    cout << "Введите первую строку: ";
    cin >> a;

    for (int i = 0; a[i] != '\0'; i++) { //определ кол раз
        if (a[i] != '0' && a[i] != '1') {
            cout << "Ошибка, неверные символы" << endl;
            return 1;
        }
    }

    len_a = 0;
    while (a[len_a] != '\0') { //пока истино
        len_a++;
    }

    if (len_a > max) {
        cout << "Неверная длина" << endl;
        return 1;
    }
    for (int i = 7; i >= 0; i--) { //опр кол раз
        if (len_a > 0) {
            a[i] = a[len_a - 1];
            len_a--;
        }
        else
            a[i] = '0';

    }
    a[8] = '\0'; //после 8 эл конец строки
    cout << "Первая строка: " << a << endl;

    cout << "Введите вторую строку: ";
    cin >> b;

    for (int i = 0; b[i] != '\0'; i++) {
        if (b[i] != '0' && b[i] != '1') {
            cout << "Ошибка, неверные символы" << endl;
            return 1;
        }
    }
    len_b = 0;
    while (b[len_b] != '\0') {
        len_b++;
    }
    if (len_b > max) {
        cout << "Неверная длина" << endl;
        return 1;
    }
    for (int i = 7; i >= 0; i--) {
        if (len_b > 0) {
            b[i] = b[len_b - 1];
            len_b--;
        }
        else
            b[i] = '0';

    }
    b[8] = '\0'; //после 8 эл конец строки
    cout << "Вторая строка: " << b << endl;


    cout << "Результат конъюнкции: ";
    for (int i = 0; i < max; i++) {
        if (a[i] == '1' && b[i] == '1')
            cout << '1';
        else
            cout << '0';
    }

    return 0;
}
