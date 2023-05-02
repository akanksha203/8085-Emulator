#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"

void INR(string registers[])
{
    int op=hexaToDecimal(registers[0]);
    registers[0]=convToHexa(++op);
}