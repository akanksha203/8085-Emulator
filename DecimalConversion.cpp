#include "headerFiles/master.hpp"

int hexaToDecimal(string s)
{
    reverse(s.begin(),s.end());
    int decimalNo=0;
    int pw=0;
    int sum=0;
    for(auto v: s)
    {
        int no=1;
        if(v >='0'&& v <='9')
        {
             no=v-48;
        }
           
        else
            no=v-55;

        sum+=no*(int)pow(16, pw);
        pw++;
    }
    return sum;

}



