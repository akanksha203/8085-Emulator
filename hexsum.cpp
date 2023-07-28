#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"

string hexsum(string arg1, string arg2,bool flag[])
{
    int op1 = hexaToDecimal(arg1);
    int op2 = hexaToDecimal(arg2);
    int sum = op1 + op2;
    bitset<8>dataInBinary(sum);
    int parity = dataInBinary.count();
    if(parity==0)
		flag[2]=true;
	else if(parity%2==0)
		flag[2]=true;
	else if(parity%2==1)
		flag[2]=false;
    
    if (sum == 0)
        flag[6] = true;
    else
        flag[6] = false;
    flag[7]=dataInBinary[7];
    

    
    flag[0] = (sum > 255); 
    
     if(((op1 & 0xF) + (op2 & 0xF)) > 0xF)
        flag[4]=true;
    
   
    string res = convToHexa(sum);
    cout<<"carry is "<<flag[0]<<endl;
    cout<<"parity is "<<flag[2]<<endl;
    cout<<"auxillary carry is "<<flag[4]<<endl;
    cout<<"zero is "<<flag[6]<<endl;
    cout<<"sign is "<<flag[7]<<endl;
    if (res.length() == 5) {
       
        res = res.substr(1);
    }
    
    return res;
}
