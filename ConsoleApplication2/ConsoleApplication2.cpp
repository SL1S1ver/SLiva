#include "BitString.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    BitString a, b, c;
    cout << "Введите битовую строку 1: " << endl;
    a.input();
    cout << "Вторую строку считаем из arbuz.txt" << endl;
    b.fileinput("arbuz.txt"); //файл создается в папке проекта, либо указать путь к файлу
    cout << "---" << endl;
    a.output();
    b.output();

    c = a.conjunction(b);
    cout << "Резулитат:";
    c.output();
    cout << "Запись результата в файл text.txt";
    c.fileoutput("text.txt");
}