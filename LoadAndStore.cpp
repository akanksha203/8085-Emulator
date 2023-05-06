
#include"headerFiles/master.hpp"
#include "headerFiles/function.hpp"

//////////////////    XCHG function//

void XCHG(string registers[])
{
    string temp;
    temp=registers[3];
    registers[3]=registers[5];
    registers[5]=temp;
    temp=registers[4];
    registers[4]=registers[6];
    registers[6]=temp;
}


//////////////          MVI 

void MVI(string arg1 ,string arg2,string registers[],map<string,string>&memory )
{
int l1=arg1.size();
int l2=arg2.size();
if(l1==1&&l2==2)
{
    if(arg1!="M"&&validRegister(arg1))
    {
        if(validData(arg2))
        {
        register[registerNumber(arg1)]=arg2;
    }
    }
   else if(arg1=="M")
    {
        string address=registers[5]+registers[6];
        if(validData(arg2))
        {
        memory[address]=arg2;
    }
    }
    else{
        cout<<"invalid content";
        exit(0);
    }
}
else{
    cout<<"invalid argument";
    exit(0);
}
}



//////////    LDA

#include "headerFiles/function.hpp"
using namespace std;
void LDA(string arg,string registers[],map<string string>&memory)
{
    int l=arg.length();
    if(l==4)
    {
       if( validAddress(arg))
       {
        registers[0]=memory[arg];
    }
    else{
        cout<<"invalid address";
    }
}
else
{
    cout<<"invlaid arg";
}
}


///////// LHLD

void LHLD(string add,string registers[],map<string,string>&memory)
{
int l=add.size();
if(l==4)
{
if (validAddress(add))
{
    registers[6]=memory[add];
    registers[5]=memory[add+"1"];
     cout<<"h"<<registers[5]<<endl;
    cout<<registers[6]<<endl;

}
else
{
    cout<<"invalid";
    exit(0);
}
}
else
{
cout<<"not a valid address";
exit(0);
}
}


/////////////  LXI

void LXI(string registers[], map<string,string>memory ,string operand)
{
    string reg = operand.substr(0,2);
    string Value = operand.substr(2,4);

    if (reg== "B") {
        registers[2] = Value.substr(0,2);
        registers[1] = Value.substr(2,2);
    } else if (reg == "D") {
        registers[4] = Value.substr(0,2);
        registers[3] = Value.substr(2,2);
    } else if (reg == "H") {
        registers[6] = Value.substr(0,2);
        registers[5] = Value.substr(2,2);
    } else if (reg == "S") {
        registers[8] = Value.substr(0,2);
        registers[7] = Value.substr(2,2);
    }
    //substr(start,length);
  
    //A0 B1 C2 D3 E4 H5 L6
}



/////////////////////   MOV

void MOV(string arg1,string arg2,string registers[],map<string,string>&memory)
{
int l1=arg1.size();
int l2=arg2.size();
if(l1==1&&l2==1)
{
    if(arg1!="M"&&arg2!="M"&&validRegister(arg1)&&validRegister(arg2))
{
    registers[registerNumber(arg1)]=registers[registerNumner(arg2)];
}
else if(arg1=="M"&&arg2!="M"&&validRegister(arg2))
{
    string address=registers[5]+registers[6];
    memory[address]=registers[registerNumber(arg2)];
}
else if(arg1!="M"||arg2=="M"&&validRegister(arg1))
{
    string address=registers[5]+registers[6];
    registers[registerNumber(arg2)]=memory[address];
}
else
{
    cout<<"invalid input";
}
}
}


/////////////////////// STA

void STA(string arg,string registers[],map<string,string>&memory)
{
    int l1=arg.length();
    if(l1==4)
    {
        if(validAddress(arg))
        {
memory[arg]=registers[0];
        }
        else{
            cout<<"invalid address";
        }
    }
    else{
        cout<<"invaid argument";
        exit (0);
    }
}
