#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"

void DCR(string registers[])
{
    int op=hexaToDecimal(registers[0]);
    registers[0]=convToHexa(--op);
}