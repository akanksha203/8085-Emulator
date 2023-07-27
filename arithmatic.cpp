#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"
#include "headerFiles/validity.hpp"
//////////////ADD
void ADD(string reg, string registers[],bool flag[], map<string,string>memory)
{
    string op1=registers[0];
    cout << "op1 is " << op1 << endl;
    if(validRegister(reg) || validRegisterPair(reg)){
         if(reg!="M")
         {
            string op2;
            op2=registers[registerNumber(reg)];
            cout << "op2 is " << op2 << endl;
        
            string sum=hexsum(op1,op2,flag);
            registers[0]=sum.substr(2);
        
         }
         else
         {
            string address=registers[5]+registers[6];
            if(validAddress(address))
            {
                string op2=memory[address];
                string sum=hexsum(op1,op2,flag);
                int res=hexaToDecimal(sum);
                flag[0]=(res>255);
            
            
            registers[0]=sum.substr(2);
            cout<<"after add m accumulator is: "<<registers[0]<<endl;
            }
            else
            {
                cout<<"Invalid address"<<endl;
                return;
            }
        }
    }
    else
    {
        cout<<"Invalid Register"<<endl;
    }
}



// ////////////////SUB
void SUB(string reg, string registers[],bool flag[], map<string,string>memory)
{
    string op1=registers[0];
    cout << "op1 is " << op1 << endl;
    if(reg!="M")
    {
        string op2;
        if(validRegister(reg)){
            op2=registers[registerNumber(reg)];
            cout << "op2 is " << op2 << endl;
            
        }
        else
        {
            cout<<"Invalid register"<<endl;
            return;
        }
        string diff=hexsub(op1,op2);
        
        int res=hexaToDecimal(diff);
        flag[0]=(res>255);
        registers[0]=diff.substr(2);
    }
    else
    {
        string address=registers[5]+registers[6];
        if(validAddress(address))
        {
            string valueStored=memory[address];
            string op2=valueStored;
            string diff=hexsub(op1,op2);
            int res=hexaToDecimal(diff);
            flag[0]=(res>255);
        
        registers[0]=diff.substr(2);
        }
        else
        {
            cout<<"Invalid address"<<endl;
            return;
        }
    }
}


////////////////DAD

void DAD(string registers[], map<string,string>memory ,bool flag[])
{
 
        string num1="";
        num1=registers[5]+registers[6];
        string op1=num1;
       

        string num2="";
        num2=registers[3]+registers[4];
        string op2=num2;
        string sum=hexsum(op1,op2,flag);
      
        
        registers[5] = sum.substr(0,2);
        registers[6] = sum.substr(2);


    

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
void INX(string arg,string registers[],map<string,string>memory)
{
          if(validRegister(arg)){
        if(arg=="B" || arg=="D" || arg=="H"){
            
            string op1="";
            op1=registers[registerNumber(arg)]+registers[registerNumber(arg)+1];
            string res=hexsum16(op1,"0001");
            registers[registerNumber(arg)]=res.substr(0,2);
            registers[registerNumber(arg)+1]=res.substr(2,2);
                 cout<<"after INX H is:"<<registers[5]<<endl;
             cout<<"after INX L is:"<<registers[6]<<endl;
        }
        else
        {
            cout<<"This register cant be used with DCX";
        }
    }
    else{
        cout<<"Invalid register!";
    }
}







////////////DCX
void DCX(string arg,string registers[],map<string,string>memory)
{
    if(validRegister(arg)){
        if(arg=="B" || arg=="D" || arg=="H"){
            
            string op1="";
            op1=registers[registerNumber(arg)]+registers[registerNumber(arg)+1];
            string res=hexsub16(op1,"0001");
            registers[registerNumber(arg)]=res.substr(0,2);
            registers[registerNumber(arg)+1]=res.substr(2,2);
        }
        else
        {
            cout<<"This register cant be used with DCX";
        }
    }
    else{
        cout<<"Invalid register!";
    }
}






////////////INR
void INR(string arg,string registers[],map<string,string>memory,bool flag[])
{
        
    if(validRegister(arg)){
        if(arg!="M" ){
        string op=registers[registerNumber(arg)];
        registers[registerNumber(arg)]=hexsum(op,"01",flag);
         cout<<"C is "<<registers[registerNumber(arg)]<<endl;
           }
      
    }
    else{
        cout<<"Invalid register"<<endl;
    }
}



////////////////DCR
void DCR(string arg, string registers[], map<string, string> memory, bool flag[])
{
    cout << "Args is: " << arg << endl;
    if (validRegister(arg))
    {
        if (arg != "M")
        {
            string op = registers[registerNumber(arg)];
            int decVal = hexaToDecimal(op);
            decVal--; 

            if (decVal < 0)
                decVal = 0;

            registers[registerNumber(arg)] = convToHexa(decVal);

            flag[6] = (decVal == 0); 
            cout << "After decrement " << arg << " is: " << registers[registerNumber(arg)] << endl;
        }
    }
    else
    {
        cout << "Invalid register" << endl;
    }
}





////////////////ADI
void ADI(string args,string registers[],bool flag[])
{
    string op1=registers[0];
    //  cout<<"OP1 is "<<op1<<endl;
    string op2=args;
    //cout<<"OP2 is "<<op2<<endl;
    string sum=hexsum(op1,op2,flag);
    cout<<"sum is "<<sum<<endl;
    registers[0]=sum.substr(2);
}







///////////////SUI
void SUI(string args,string registers[])
{
    int op1=stoi(registers[0]);
   //   cout<<"OP1 is "<<op1<<endl;
    int op2=stoi(args);
   // cout<<"OP2 is "<<op2<<endl;
    int diff=op1-op2;
    cout<<"diff is "<<diff<<endl;
    registers[0]=convToHexa(diff);
}



/////////////CMP
void CMP(string arg,string registers[],bool flag[],map<string,string>&memory)
{
    string op1=registers[0];
    if(arg!="M")
    {
         if(validRegister(arg)){
            string op2=registers[registerNumber(arg)];
           
            if(op1==op2)
            {
                flag[6]=true;
            }
            else if(op1<op2)
            {
                flag[0]=true;
        
            }
            else if(op1>op2)
            {
                    flag[0]=false;
                    flag[6]=false;
            }
        }
    }
    else
    {
         string num1="";
        num1=registers[5]+registers[6];
        string op2=memory[num1];
         if(op1==op2)
            {
                flag[6]=true;
            }
            else if(op1<op2)
            {
                flag[0]=true;
        
            }
            else if(op1>op2)
            {
                    flag[0]=false;
                    flag[6]=false;
            }

    }
    cout<<flag[0]<<endl<<flag[1]<<endl<<flag[2]<<endl<<flag[3]<<endl<<flag[4]<<endl<<flag[5]<<endl<<flag[6]<<endl<<flag[7];
}






