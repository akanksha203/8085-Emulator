#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"

void INR(String register[])
{
    int op=HexaToDecimal(register[0]);
    register[0]=convToHexa(++op);
}