#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"
void MVI(string arg1 ,string arg2,string register[],map<string,string>&memory )
{
int l1=arg1.size();
int l2=arg2.size();
if(l1==1&&l2==2)
{
    if(arg1!="M"&&validRegister(arg1))
    {
        if(validData(arg2))
        {
register[registerNumber(arg1)]=arg2;
    }
    }
   else if(arg1=="M")
    {
        address=register[5]+register[6];
        if(validData(arg2))
        {
        memory[address]=arg2;
    }
    }
    else{
        cout<<"invalid content";
        exit(0);
    }
}
else{
    cout<<"invalid argument";
    exit(0);
}
}