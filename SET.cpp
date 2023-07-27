#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"
#include "headerFiles/validity.hpp"

void SET(string address,string val,map<string,string> &memory)
{
    if(validAddress(address)&&validData(val))
    {
        memory[address]=val;
        cout<<"Memory "<<address<<" has:"<<memory[address]<<endl;
    }
    else
    {
        cout<<"INVALID INPUT OF DATA";
        
    }
}
