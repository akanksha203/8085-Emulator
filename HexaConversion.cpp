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

    while(hexa.size()<4)
    {
        hexa="0"+hexa;
    }
    return hexa;
}
<<<<<<< HEAD

int main()
{
    cout<<convToHexa(12);
}
=======
>>>>>>> 667c2ca7761eb60d24d63e8c14685b6e3a217553
