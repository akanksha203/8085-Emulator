
#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"
#include "headerFiles/validity.hpp"

//////////////////    XCHG 
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
    cout<<"REGISTER IS "<<arg1<<" AND VALUE IS "<<arg2;
    if(arg1!="M"&&validRegister(arg1))
    {
        if(validData(arg2))
        {
         registers[registerNumber(arg1)]=arg2;
         
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
void LDA(string arg,string registers[],map<string,string>memory)
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
        cout<<"invlaid argument";
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
           int nextAddress = hexaToDecimal(add) + 1;
            registers[5] = memory[convToHexa(nextAddress)];

          
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


/////////////SHLD
void SHLD(string add, string registers[], map<string,string>&memory)
{
    int l = add.size();
    if (l == 4)
    {
        if (validAddress(add))
        {
            memory[add] = registers[6];
            cout<<add<<":"<<memory[add]<<endl;
            int nextAddress = hexaToDecimal(add) + 1;
            memory[convToHexa(nextAddress)] = registers[5];
           cout<< convToHexa(nextAddress)<<":"<<memory[convToHexa(nextAddress)];
        }
        else
        {
            cout << "Invalid memory address" << endl;
            exit(0);
        }
    }
    else
    {
        cout << "Not a valid address" << endl;
        exit(0);
    }

}

/////////////  LXI
void LXI(string args1, string args2, string registers[], map<string, string> memory)
{
    if (args1 == "B") {
        registers[1] = args2.substr(0, 2); 
        registers[2] = args2.substr(2); 
    } else if (args1 == "D") {
        registers[3] = args2.substr(0, 2); 
        registers[4] = args2.substr(2); 
    } else if (args1 == "H") {
        registers[5] = args2.substr(0, 2); 
        registers[6] = args2.substr(2); 
    } else if (args1 == "SP") {
        registers[7] = args2.substr(0, 2); 
        registers[8] = args2.substr(2); 
   
    }
         cout<<"H is:"<<registers[5]<<endl;
        cout<<"L is:"<<registers[6]<<endl;
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
    registers[registerNumber(arg1)]=registers[registerNumber(arg2)];

}
else if(arg1=="M"&&arg2!="M"&&validRegister(arg2))
{
    string address=registers[5]+registers[6];
    memory[address]=registers[registerNumber(arg2)];
    cout<<"M is :"<<address<<" VALUE IS "<<memory[address]<<endl;
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


//////////STAX
void STAX(string arg,string registers[],map<string,string>&memory)
{
    if(validRegisterPair(arg))
    {
        string address="";
        address=registers[registerNumber(arg)]+registers[registerNumber(arg)+1];
        if(validAddress(address))
        {
            memory[address]=registers[0];
        }
        cout<<"STAX memory address has "<<address<<" "<<memory[address]<<endl;
    }
}