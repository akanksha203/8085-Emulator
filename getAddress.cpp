#include "headerFiles/master.hpp"
#include  "headerFiles/function.hpp"
#include <sstream>

string getAddress(string x, string pc)
{
        int pcValue=hexaToDecimal(pc);
        stringstream statement(x);
        string temp;
        getline(statement,temp,' ');
        int count=opcodeFetch(temp);        
        pcValue+=count;
        return convToHexa(pcValue);
}