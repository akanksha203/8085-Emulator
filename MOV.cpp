#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"
#include "headerFiles/validity.hpp"
void MOV(string arg1,string arg2,string registers[],map<string,string>&memory)
{
int l1=arg1.size();
int l2=arg2.size();
if(l1==1&&l2==1)
{
    if(arg1!="M"&&arg2!="M"&&validRegister(arg1)&&validRegister(arg2))
{
    registers[registerNumber(arg1)]=registers[registerNumber(arg2)];
}
else if(arg1=="M"&&arg2!="M"&&validRegister(arg2))
{
    string address=registers[5]+registers[6];
    memory[address]=registers[registerNumber(arg2)];
}
else if(arg1!="M"||arg2=="M"&&validRegister(arg1))
{
    string address=registers[5]+registers[6];
    registers[registerNumber(arg2)]=memory[address];
}
else
{
    cout<<"invalid input";
}
}
}