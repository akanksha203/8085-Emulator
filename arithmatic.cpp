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
            
            registers[0]=sum.substr(2);
            cout<<"after add m accumulator is: "<<registers[0]<<endl;
            }
            else
            {
                cout<<"Invalid address"<<endl;
                exit(0);
            }
        }
    }
    else
    {
        cout<<"Invalid Register"<<endl;
        exit(0);
    }
}



// ////////////////SUB
void SUB(string reg, string registers[],bool flag[], map<string,string>memory)
{
    string op1=registers[0];
    cout << "op1 is " << op1 << endl;
    if(validRegister(reg) || validRegisterPair(reg)){
        if(reg!="M")
        {
            string op2;
            op2=registers[registerNumber(reg)];
            cout << "op2 is " << op2 << endl;
            string diff=hexsub(op1,op2,flag);
            registers[0]=diff.substr(2);
        }
        else
        {
            string address=registers[5]+registers[6];
            if(validAddress(address))
            {
                string valueStored=memory[address];
                string op2=valueStored;
                string diff=hexsub(op1,op2,flag);
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
    else{
         cout<<"Invalid Register"<<endl;
        exit(0);
    }
}


////////////////DAD

void DAD(string command,string arg,string registers[], map<string,string>memory ,bool flag[])
{
    if(validRegister(arg)){
        if(arg=="B"||arg=="D"||arg=="H"){
            string num1="";
            num1=registers[5]+registers[6];
            string op1=num1;
        

            string num2="";
            num2=registers[registerNumber(arg)]+registers[registerNumber(arg)+1];
            string op2=num2;
            string sum=hexsum16(command,op1,op2,flag);
        
            
            registers[5] = sum.substr(0,2);
            registers[6] = sum.substr(2);
        }
        else{
            cout<<"Invalid register pair"<<endl;
            exit(0);

        }

    }
    else{
        cout<<"Invalid argument"<<endl;
        exit(0);
    }
    

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
   cout<<"carry is "<<flag[0]<<endl;
    cout<<"parity is "<<flag[2]<<endl;
    cout<<"auxillary carry is "<<flag[4]<<endl;
    cout<<"zero is "<<flag[6]<<endl;
    cout<<"sign is "<<flag[7]<<endl;
}


//////////////INX
void INX(string command,string arg,string registers[],map<string,string>memory,bool flag[])
{
    if(validRegister(arg)){
        if(arg=="B" || arg=="D" || arg=="H"){
            if(validData(registers[registerNumber(arg)]) == true && validData(registers[registerNumber(arg)+1]) == true){
			
                string op1="";
                op1=registers[registerNumber(arg)]+registers[registerNumber(arg)+1];
                string res=hexsum16(command,op1,"0001",flag);
                registers[registerNumber(arg)]=res.substr(0,2);
                registers[registerNumber(arg)+1]=res.substr(2,2);
                    cout<<"after INX H is:"<<registers[5]<<endl;
                cout<<"after INX L is:"<<registers[6]<<endl;
            }
            else{
                cout<<"Invalid data content";
                exit(0);
            }
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
void DCX(string command,string arg,string registers[],map<string,string>memory,bool flag[])
{
    if(validRegister(arg)){
        if(arg=="B" || arg=="D" || arg=="H"){
            if(validData(registers[registerNumber(arg)]) == true && validData(registers[registerNumber(arg)+1]) == true){
				
                string op1="";
                op1=registers[registerNumber(arg)]+registers[registerNumber(arg)+1];
                string res=hexsub16(command,op1,"0001",flag);
                registers[registerNumber(arg)]=res.substr(0,2);
                registers[registerNumber(arg)+1]=res.substr(2,2);
                cout<<"after DCX H is:"<<registers[5]<<endl;
                cout<<"after DCX L is:"<<registers[6]<<endl;
            }
            else{
                cout<<"Invalid data content";
                exit(0);
            }
        }
        else
        {
            cout<<"This register cant be used with DCX";
            exit(0);
        }
    }
    else{
        cout<<"Invalid register!";
        exit(0);
    }
}






////////////INR
void INR(string arg,string registers[],map<string,string>memory,bool flag[])
{
        
        if(arg!="M" ){
            if(validRegister(arg)){
                string op=registers[registerNumber(arg)];
                registers[registerNumber(arg)]=hexsum(op,"01",flag);
                cout<<"C is "<<registers[registerNumber(arg)]<<endl;
            }
             else{
                cout<<"Invalid register"<<endl;
                exit(0);
             }
        }
        else if(arg=="M")
        {
                string address = "";
				address = registers[5] + registers[6];
               
				if(validAddress(address)){
                    cout<<"Earlier "<<memory[address]<<endl;
					memory[address] = hexsum(memory[address],"01",flag);
                    cout<<"AFter "<<memory[address]<<endl;
                }
				else{
					cout<<"Invalid address";
					exit(0);
					
				}
        }
        else{
            cout<<"Invalid argument";
            exit(0);
        }
   
}



////////////////DCR
void DCR(string arg, string registers[], map<string, string> memory, bool flag[])
{
        if(arg!="M" )
        {
            if(validRegister(arg)){
                string op=registers[registerNumber(arg)];
                registers[registerNumber(arg)]=hexsub(op,"01",flag);
                cout<<"C is "<<registers[registerNumber(arg)]<<endl;
            }
            else{
                cout<<"Invalid register"<<endl;
                exit(0);
            }
        }
        else if(arg=="M")
        {
                string address = "";
				address = registers[5] + registers[6];
               
				if(validAddress(address)){
                    //cout<<"Earlier "<<memory[address]<<endl;
					memory[address] = hexsub(memory[address],"01",flag);
                    //cout<<"AFter "<<memory[address]<<endl;
                }
				else{
					cout<<"Invalid address";
					exit(0);
					
				}
        }
        else{
            cout<<"Invalid argument";
            exit(0);
        }
      
}






////////////////ADI
void ADI(string arg,string registers[],bool flag[])
{
    if(validData(arg)){
        string op1=registers[0];
        string op2=arg;
        string sum=hexsum(op1,op2,flag);
        cout<<"sum is "<<sum<<endl;
        registers[0]=sum.substr(2);
    }
    else{
        cout<<"Invalid content"<<endl;
        exit(0);
    }
}







///////////////SUI
void SUI(string args,string registers[],bool flag[])
{
       string op1=registers[0];
    //  cout<<"OP1 is "<<op1<<endl;
    string op2=args;
    //cout<<"OP2 is "<<op2<<endl;
    string diff=hexsub(op1,op2,flag);
    cout<<"diff is "<<diff<<endl;
    registers[0]=diff.substr(2);
}



/////////////CMP
void CMP(string arg, string registers[], bool flag[], map<string, string>& memory) {
    string op1 = registers[0];
    if (arg != "M") {
        string op2 = registers[registerNumber(arg)];

        if (validRegister(arg)) {
            hexsub(op1, op2, flag);
        }
     } 
     else if (arg == "M") {
        string num1 = registers[5] + registers[6];
        string op2 = memory[num1];
        hexsub(op1, op2, flag);
    } 
    else {
        cout << "Invalid register" << endl;
    }

}
