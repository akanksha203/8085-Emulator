#include "headerFiles/master.hpp"

string convToHexa(int number)
{
    string hexa="";
    while(number!=0)
    {

        int rem=(number%16);
        if(rem>9)
            rem=(rem+55);
        else
            rem=(rem+48);
        char ch=(char)rem;
        hexa=hexa+ch;
        number/=16;
    
    }

    reverse(hexa.begin(),hexa.end());
    return hexa;
}
