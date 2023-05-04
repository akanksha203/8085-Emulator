#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"
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