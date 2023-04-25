#include"headerFiles/master.hpp"

void XCHG(string registers[])
{
    string temp;
    temp=registers[3];
    registers[3]=registers[5];
    registers[5]=temp;
    temp=registers[4];
    registers[4]=registers[6];
    registers[6]=temp;
}