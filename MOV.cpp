#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"
void mov(string arg1,string arg2,string register[],map<string,string>&memory)
{
int l1=arg1.size();
int l2=arg2.size();
if(l1==1&&l2==1)
{
    if(arg1!="M"&&arg2!="M"&&validRegister(arg1)&&validRegister(arg2))
{
    register[registerNumber(arg1)]=register[registerNumner(arg2)];
}
else if(arg1=="M"&&arg2!="M"&&validRegister(arg2))
{
    string address=register[5]+register[6];
    memory[address]=register[registerNumber(arg2)];
}
else if(arg1!="M"||arg2=="M"&&validRegister(arg1))
{
    string address=register[5]+register[6];
    register[registerNumber(arg2)]=memory[address];
}
else
{
    cout<<"invalid input";
}
}
}