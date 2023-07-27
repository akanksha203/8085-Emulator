#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"
#include "headerFiles/validity.hpp"


void GET(string address,map<string,string> &memory)
{
    try{
        cout<<address<<":"<<memory[address]<<endl;
    }
    catch(string address){
        cout<<address<<":"<<"00"<<endl;
    }
}