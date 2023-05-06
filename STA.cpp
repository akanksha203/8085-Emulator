#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"
void STA(string arg,string registers[],map<string,string>&memory)
{
    int l1=arg.length();
    if(l1==4)
    {
        if(validAddress(arg))
        {
            memory[arg]=registers[0];
        }
        else{
            cout<<"invalid address";
        }
    }
    else{
        cout<<"invaid argument";
        exit (0);
    }
}