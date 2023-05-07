#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"

void DCX(string registers[],map<string,string>memory)
{
        string address="";
        address=registers[5]+registers[6];
        string valueStored=memory[address];
        int value=hexaToDecimal(valueStored);
        value--;
        address=convToHexa(value);
        registers[5]=address.substr(0,2);
        registers[6]=address.substr(2,2);
}