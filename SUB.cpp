#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"
#include "headerFiles/validity.hpp"

void SUB(string reg, string registers[], map<string,string> memory)
{
    int op1=hexaToDecimal(registers[0]);
    if(reg!="M")
    {
        int op2;
        if(reg!="H"||reg!="L")
        op2=hexaToDecimal(registers[registerNumber(reg)]);
        else if(reg=="H")
        op1=hexaToDecimal(registers[5]);
        else
        op1=hexaToDecimal(registers[6]);
        int diff=op2-op1;
       // cout<<"DIFFERENCE IS :"<<diff<<endl;
        registers[0]=convToHexa(diff);
    }

    else
    {
        string address="";
        address=registers[5]+registers[6];
        string valueStored=memory[address];
        int op2=hexaToDecimal(valueStored);
        int sum=op1-op2;
        registers[0]=convToHexa(sum);

    }
}


