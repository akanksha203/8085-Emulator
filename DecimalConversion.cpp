#include "headerFiles/master.hpp"

int HexaTodecimal(string s)
{
    int decimalNo=0;
    int pw=0;
    int sum=0;
    for(auto v: s)
    {
        int no;
        if(v >='0'&& v <='9')
            no=v-48;
        else
            no=v-55;

        sum+=no*pow(16, pw);
        pw++;
    }
    return sum;

}


int main()
{

    cout<<HexaTodecimal("FFF");

}