#include "header files/master.hpp"

void opcodeSize(string command)
{
    string one[]={"HLT","MOV","DCR","INR","INX","DCX","SUB","ADD","CMA","CMP","XCHG","DAD","STAX"};
    string two[]={"MVI","ADI","SUB"};
    string three[]={"STA","SET","LXI","LDA","STA","SHLD","LHLD","JMP","JC","JNZ","JNC","JZ","SET"};

    for(int i=0;i<13;i++)
    {
        if(command==one[i])
            {
            return 1;
            }    
    }

     for(int i=0; i<3; i++)
    {
        if(command==two[i])
            {
            return 2;
            }      
    }

     for(int i=0; i<13; i++)
    {
        if(command==three[i])
            {
            return 3;
            }
               
    }


}