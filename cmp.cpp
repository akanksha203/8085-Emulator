
#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"
void cmp(string arg,string register[],bool flag[],map<string,string>&memory)
{
int l=arg.length();
if(l==1)
{
    if(arg=="M")
    {string address=register[5]+register[6];

if(register[0]<memory[address])
{
    flag[c]=true;
}
else if(register[0]==memory[address])
{
    flag[z]=true;
}
else{
    flag[c]=false;
    flag[z]=false;
}
    }
    else if(validRegister(arg))
    {
        int index=registerNumber(arg);
        {
            if(register[0]<register[index])
            {
                flag[c]=0;
            }
            else if(register[0]==register[index])
            {
                flag[z]=0;
            }
                else{
                    flag[z]=0;
                    flag[c]=0;
                }
        }
            else{
                cout<<"error invlaid register";
                exit(0);
            }
        }
        else{
            cout<<"invalid argument";
            exit(0);
        }
    }
}
