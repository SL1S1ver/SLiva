#include "BitString.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//--- по умол
BitString::BitString() {
    for (int j = 0; j < 8; j++) bs[j] = '0';
}
//--- с парам
BitString::BitString(string inp_string) {
    for (int j = 0; j < 8; j++) bs[j] = '0';
    char tmp;
    unsigned char tmps[8];
    for (int j = 0; j < 8; j++) tmps[j] = '0';
    int i = 0;

    tmp = inp_string[i];
    while (tmp != '\0') {
        if (((tmp != '0') && (tmp != '1')) || (i >= 8))
        {
            cout << "Некорректный символ" << endl;
            exit(0);
        }
        tmps[i] = (unsigned char)tmp;
        i++;
        tmp = inp_string[i];
    }

    i--;
    for (int j = 0; j <= i; j++)
        bs[7 - i + j] = tmps[j];
}
//--- ввод с клавы
void BitString::input()
{
    char tmp;
    unsigned char tmp8[8];
    for (int j = 0; j < 8; j++) tmp8[j] = '0';
    int i = 0;
    cin.get(tmp);
    while (tmp != '\n') {
        if ((tmp != '0' && (tmp != '1')) || (i >= 8))
        {
            cout << "Некорректный ввод" << endl;
            exit(0);
        }
        tmp8[i] = (unsigned char)tmp;
        cin.get(tmp);
        i++;
    }
    i--;
    for (int j = 0; j <= i; j++)
        bs[7 - i + j] = tmp8[j];
}

//-- вывод на экран
void BitString::output()
{
    for (int j = 0; j < 8; j++)
        cout << bs[j];
    cout << endl;
}

//-- конь
BitString BitString::conjunction(BitString b)
{
    char tmp[9];
    for (int j = 0; j < 8; j++) tmp[j] = '0';
    for (int j = 0; j < 8; j++) {
        if ((bs[j] == '1') && (b.bs[j] == '1')) tmp[j] = '1';
        else tmp[j] = '0';
    }
    tmp[8] = '\0';
    return BitString(std::string(tmp));
}
//-- запись в файл
void BitString::fileoutput(string filename) {
    ofstream file(filename);
    file << "Резулитат: ";
    for (int j = 0; j < 8; j++) file << bs[j];
    file.close();
}
//--- чтение из ф
void BitString::fileinput(string filename)
{
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Открыть файл не удалось" << endl;
        exit(0);
    }

    char tmp;
    unsigned char tmp8[8];
    for (int j = 0; j < 8; j++)
        tmp8[j] = '0';
    int i = 0;
    while (file.get(tmp)) {
        if (((tmp != '0') && (tmp != '1')) || (i >= 8))
        {
            cout << "Некорректный символ" << endl;
            exit(0);
        }
        tmp8[i] = (unsigned char)tmp;
        i++;
    }
    i--;
    for (int j = 0; j <= i; j++)
        bs[7 - i + j] = tmp8[j];

    file.close();
}
