#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"


//////////////////ADDD

void ADD(int reg, string registers[], map<string,string> memory)
{
    int op1=hexaToDecimal(registers[0]);
    if(reg!='M')
    {
        int op2;
        if(reg!='H'||reg!='L')
        op2=hexaToDecimal(registers[reg-65]);
        else if(reg=='H')
        op1=hexaToDecimal(registers[5]);
        else
        op1=hexaToDecimal(registers[6]);
        int sum=op1+op2;
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



/////DAD

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

//////      DCX

void DCX(String registers[])
{
        string address="";
        address=registers[5]+registers[6];
        int value=hexaToDecimal(valueStored);
        value--;
        address=convToHexa(value);
        registers[5]=address.substr(0,2);
        registers[6]=address.substr(2,2);
}


///////     INR

void INR(string registers[])
{
    int op=hexaToDecimal(registers[0]);
    registers[0]=convToHexa(++op);
}


/////       INX

void INX(String registers[])
{
        string address="";
        address=registers[5]+registers[6];
        int value=hexaToDecimal(valueStored);
        value++;
        address=convToHexa(value);
        registers[5]=address.substr(0,2);
        registers[6]=address.substr(2,2);
}


////////        SUB

void SUB(int reg, string registers[], map<string,string> memory)
{
    int op1=hexaToDecimal(registers[0]);
    if(reg!='M')
    {
        int op2;
        if(reg!='H'||reg!='L')
        op2=hexaToDecimal(registers[reg-65]);
        else if(reg=='H')
        op1=hexaToDecimal(registers[5]);
        else
        op1=hexaToDecimal(registers[6]);
        int sum=op1-op2;
        registers[0]=convToHexa(sum);
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

////////     DCR

void DCR(String registers[])
{
    int op=HexaToDecimal(registers[0]);
    registers[0]=convToHexa(--op);
}