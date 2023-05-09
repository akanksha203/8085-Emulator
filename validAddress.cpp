#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"

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