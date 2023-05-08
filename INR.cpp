#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"
#include "headerFiles/validity.hpp"

void INR(string arg,string registers[])
{
    if(arg!="M" && arg!="H" && arg!="L"){
    int op=hexaToDecimal(registers[registerNumber(arg)]);
    registers[registerNumber(arg)]=convToHexa(++op);
    }
}