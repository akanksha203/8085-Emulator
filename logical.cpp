#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"

///////////JC
string JC(string address, string pc, bool flag[], vector<string> sequence)
{
    if (flag[0]) {
        pc = address;
    } 
    else {
        
        for (int i = 0; i < sequence.size(); i++) {
            if (pc == sequence[i]) {
                if (i + 1 < sequence.size()) {
                    pc = sequence[i + 1];
                }
                break;
            }
        }
    }

    return pc;
}









//////////////JNC
string JNC(string address, string pc, bool flag[], vector<string> sequence)
{
    if (!flag[0]) {
        pc = address;
    } else {
        for (int i = 0; i < sequence.size(); i++) {
            if (pc == sequence[i]) {
                if (i + 1 < sequence.size()) {
                    pc = sequence[i + 1];
                }
                break;
            }
        }
    }

    return pc;
}











///////////////JZ

string JZ(string address, string pc, bool flag[], vector<string> sequence)
{
    if (flag[6]) 
    {
        pc = address;
    }
    else
    {
        for (int i = 0; i < sequence.size(); i++)
        {
            if (pc == sequence[i])
            {
                if (i + 1 < sequence.size())
                {
                    pc = sequence[i + 1];
                }
                break;
            }
        }
    }

    return pc;
}











/////////////////JNZ
string JNZ(string address, string pc, bool flag[], vector<string> sequence)
{
    if (!flag[6])
    {
        pc = address;
    }
    else
    {
        int i = 0;
        for (; i < sequence.size(); i++)
        {
            if (pc == sequence[i])
                break;
        }
        if (i + 1 < sequence.size())
        {
            pc = sequence[i + 1];
        }
    }

    return pc;
}

/////////////////JMP
string JMP(string arg)
{
    if(validAddress(arg)){
    return arg;
    }
}