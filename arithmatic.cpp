#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"
#include "headerFiles/validity.hpp"

//////////////ADD
void ADD(string reg,string registers[],map<string,string> memory)
{
    int op1=hexaToDecimal(registers[0]);
    cout<<"op1 is"<<op1<<endl;
    if(reg!="M")
    {
        int op2;
        if(reg!="H"||reg!="L"){
        op2=hexaToDecimal(registers[registerNumber(reg)]);
        cout<<"op2 is:"<<op2<<endl;
        }
        else if(reg=="H")
        op1=hexaToDecimal(registers[5]);
        else
        op1=hexaToDecimal(registers[6]);
        int sum=op1+op2;
        cout<<"SUM IS:"<<sum<<endl;
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


////////////////SUB
void SUB(string reg, string registers[], map<string,string>memory)
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


////////////////DAD

void DAD(string registers[], map<string,string>memory ,bool flag[])
{
 
        string num1="";
        num1=registers[5]+registers[6];
        int op1=hexaToDecimal(num1);
       

        string num2="";
        num2=registers[3]+registers[4];
        int op2=hexaToDecimal(num2);
        int sum=op1+op2;
      
        int lower8Bits = sum & 0xFF;
        registers[5] = convToHexa(lower8Bits);
        int upper8Bits = (sum >> 8) & 0xFF;
        registers[6] = convToHexa(upper8Bits);

    

}



//////////CMA
void CMA(string registers[],bool flag[]) {
    int op1 = hexaToDecimal(registers[0]);

    vector<int> binaryNum;
    while (op1 > 0) {
        binaryNum.push_back(op1 % 2);
        op1 = op1 / 2;
    }
    while (binaryNum.size() < 8) {
        binaryNum.push_back(0);
    }

    reverse(binaryNum.begin(), binaryNum.end());

    for (int i = 0; i < binaryNum.size(); i++) {
        if (binaryNum[i] == 1) {
            binaryNum[i] = 0;
        } else {
            binaryNum[i] = 1;
        }
    }

    int decimal = 0;
    int k = 0;
    for (int i = binaryNum.size() - 1; i >= 0; i--) {
        decimal += binaryNum[i] * pow(2, k);
        k++;
    }

    registers[0] = convToHexa(decimal);
    if(binaryNum[0]==1)
       flag[7]=true;
    if (decimal==0)
       flag[6]=true;
}


//////////////INX
void INX(string registers[],map<string,string>memory)
{
        string address="";
        address=registers[5]+registers[6];
        string valueStored=memory[address];
        int value=hexaToDecimal(valueStored);
        value++;
        address=convToHexa(value);
        registers[5]=address.substr(0,2);
        registers[6]=address.substr(2,2);
}







////////////DCX
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






////////////INR
void INR(string arg,string registers[])
{
    if(arg!="M" && arg!="H" && arg!="L"){
    int op=hexaToDecimal(registers[registerNumber(arg)]);
    registers[registerNumber(arg)]=convToHexa(++op);
    }
}










/////////////DCR

void DCR(string registers[])
{
    int op=hexaToDecimal(registers[0]);
    registers[0]=convToHexa(--op);
}
