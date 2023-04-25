#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"

void SUB(int reg, string register[], map<string,string> memory)
{
    int op1=hexaToDecimal(register[0]);
    if(reg!='M')
    {
        int op2;
        if(reg!='H'||reg!='L')
        op2=hexaToDecimal(register[reg-65]);
        else if(reg=='H')
        op1=hexaToDecimal(register[5]);
        else
        op1=hexaToDecimal(register[6]);
        int sum=op1-op2;
        register[0]=convToHexa(sum);
    }

    else
    {
        string address="";
        address=register[5]+register[6];
        string valueStored=memory[address];
        int op2=hexaToDecimal(valueStored);
        int sum=op1-op2;
        register[0]=convToHexa(sum);

    }
}


