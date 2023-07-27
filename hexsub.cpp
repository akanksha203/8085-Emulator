#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"

string hexsub(string arg1, string arg2,bool flag[])
{
    int op1 = hexaToDecimal(arg1);
    int op2 = hexaToDecimal(arg2);
    int diff = op1 - op2;
    bitset<8>dataInBinary(diff);
    int parity = dataInBinary.count();
    if (parity % 2 == 0 && parity != 0)
        flag[2] = true;
    else
        flag[2] = false;
    flag[7]=dataInBinary[7];
    if (parity == 0)
        flag[6] = true;

    
    flag[0] = (sum > 255); 
    
     flag[4] = ((op1 & 0xF) + (op2 & 0xF)) > 0xF;
    
   
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
