#pragma once
#include <string>
using namespace std;

class BitString
{
    unsigned char bs[8];

public:
    BitString();
    BitString(string inp_string);
    void input();
    void output();
    BitString conjunction(BitString b);
    void fileoutput(string filename);
    void fileinput(string filename);
};
