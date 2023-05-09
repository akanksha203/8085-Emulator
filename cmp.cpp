
#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"
void CMP(string arg,string registers[],bool flag[],map<string,string>&memory)
{
int l=arg.length();
if(l==1)
{
    if(arg=="M")
    {string address=registers[5]+registers[6];

if(registers[0]<memory[address])
{
    flag[c]=true;
}
else if(registers[0]==memory[address])
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
            if(registers[0]<registers[index])
            {
                flag[c]=0;
            }
            else if(registers[0]==registers[index])
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
