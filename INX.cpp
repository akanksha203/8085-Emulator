#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"

void INX(String register[])
{
        string address="";
        address=register[5]+register[6];
        int value=hexaToDecimal(valueStored);
        value++;
        address=convToHexa(value);
        register[5]=address.substr(0,2);
        register[6]=address.substr(2,2);
}