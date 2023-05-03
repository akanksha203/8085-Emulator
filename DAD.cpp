#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"

void DAD(string registers[], map<string,string>memory ,bool flag[])
{
        string address1="";
        address1=registers[5]+registers[6];
        string valueStored1=memory[address1];
        int op1=hexaToDecimal(valueStored1);

        string address2="";
        address2=registers[3]+registers[4];
        string valueStored2=memory[address2];
        int op2=hexaToDecimal(valueStored2);
        int total =op1+op2;
        
        int h1=hexaToDecimal(registers[6]+registers[5]);
        h1=h1+total;

        if(h1>0xFFFF)
        {
            h1=h1 & 0xFFFF;
         flag[0]=true;
        }
        else
          flag[0]=false;
        string news=convToHexa(h1);
        registers[6]=news.substr(0,2);
        registers[5]=news.substr(2,2);
    //A0 B1 C2 D3 E4 H5 L6
    // register[6]=register[6]+register[4];
    // register[7]=register[7]+register[5];
    // hexaToDecimal(register[reg-65]);

}
