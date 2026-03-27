#include <iostream>
#include <fstream>
using namespace std;

void input(unsigned char m[8]) {
    unsigned char temp_bs[8] = { '0', '0', '0', '0', '0', '0', '0', '0' };
    char tmp;
    int kol = 0;
    cout << "Введите строку:";
    cin.get(tmp);
    while (tmp != '\n') {
        if ((tmp != '0' && tmp != '1') || (kol >= 8)) {
            cout << "Неверные символы";
            exit(0);
        }
        temp_bs[kol] = tmp;
        cin.get(tmp);
        kol++;
    }
    for (int i = 0; i < kol; i++) {
        m[8 - kol + i] = temp_bs[i];
    }
}

void fileinput(string arbuz, unsigned char m[8]) {
    ifstream file(arbuz);
    if (!file.is_open()) {
        cout << "Файл не найден!" << endl;
        exit(0);
    }

    unsigned char temp_bs[8] = { '0', '0', '0', '0', '0', '0', '0', '0' };
    char tmp;
    int kol = 0;

    while (file.get(tmp)) {
        if ((tmp != '0' && tmp != '1') || (kol >= 8)) {
            cout << "Неверные символы!";
            exit(0);
        }
        temp_bs[kol] = tmp;
        kol++;
    }

    for (int i = 0; i < kol; i++) {
        m[8 - kol + i] = temp_bs[i];
    }
    file.close();
}

void output(unsigned char m[8]) {
    cout << "строка = ";
    for (int i = 0; i < 8; i++) {
        cout << m[i];
    }
    cout << endl;
}

void fileoutput(string arbuz, unsigned char m[8]) {
    ofstream file(arbuz);
    file << "строка = ";
    for (int i = 0; i < 8; i++) {
        file << m[i];
    }
    file.close();
}

void conyunc(unsigned char s1[8], unsigned char s2[8], unsigned char s3[8]) {
    for (int i = 0; i < 8; i++) {
        if ((s1[i] == '1') && (s2[i] == '1'))
            s3[i] = '1';
        else
            s3[i] = '0';
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    unsigned char bs1[8] = { '0', '0', '0', '0', '0', '0', '0', '0' };
    unsigned char bs2[8] = { '0', '0', '0', '0', '0', '0', '0', '0' };
    unsigned char res[8] = { '0', '0', '0', '0', '0', '0', '0', '0' };

    fileinput("arbuz.txt", bs1);

    input(bs2);

    cout << "Строка 1: ";
    output(bs1);
    cout << endl;

    cout << "Строка 2: ";
    output(bs2);
    cout << endl;

    conyunc(bs1, bs2, res);
    output(res);

    return 0;
}
