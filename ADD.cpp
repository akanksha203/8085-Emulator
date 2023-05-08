#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"
#include "headerFiles/validity.hpp"

void ADD(string reg,string registers[],map<string,string> memory)
{
    int op1=hexaToDecimal(registers[0]);
    //cout<<op1<<endl;
    if(reg!="M")
    {
        int op2;
        if(reg!="H"||reg!="L"){
        op2=hexaToDecimal(registers[registerNumber(reg)]);
        //cout<<"op2 is:"<<op2<<endl;
        }
        else if(reg=="H")
        op1=hexaToDecimal(registers[5]);
        else
        op1=hexaToDecimal(registers[6]);
        int sum=op1+op2;
       // cout<<"SUM IS:"<<sum<<endl;
        registers[0]=convToHexa(sum);
         
    }

    else
    {
        string address="";
        address=registers[5]+registers[6];
        string valueStored=memory[address];
        int op2=hexaToDecimal(valueStored);
        int sum=op1+op2;
        registers[0]=convToHexa(sum);

    }
}


