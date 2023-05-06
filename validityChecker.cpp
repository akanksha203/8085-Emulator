#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"

bool validRegisterPair(string reg)
{
    if(reg=="B"||reg=="D"||reg=="H"||reg=="M")
    return true;
    else
    return false;
}

bool validRegister(string reg)
{
if(reg=="A"||reg=="B"||reg=="C"||reg=="D"||reg="E"||reg=="H"||reg=="L")
return true;
else
return false;
}


bool ishexa(char str)
{
    if((a>='0'&&a<='9')||(a<='A'&&a>='F'))
    return true;
    else
    return false;
}
bool validData(string str)
{
    int l=str.length();
    if(l==2&&ishexa(str[0])&&ishexa(str[1]))
    return true;
    else
    return false;
}


bool validAddress(string str)
{
    bool flag;
    int len=str.length();
    for(int i=0;i<len;i++)
    {
        if((str[i]>='0'&&str[i]<='9')||(str[i]<='A'&&str[i]<='F'))
    flag=true;
    else
    flag=false;
    }
    return flag;
}


int registerNumber(string str)
{
if(str=="A")
return 0;
if(str=="B")
return 1;
if(str=="C")
return 2;
if(str=="D")
return 3;
if(str=="E")
return 4;
if(str=="H")
return 5;
if(str=="L")
return 6;
return 0;
}