#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"

void CMA(string registers[])
{
        
        int op1=hexaToDecimal(registers[0]);
    vector<int>binaryNum;
    int i = 0;
    while (op1 > 0) {
        binaryNum.push_back(op1 % 2);
        op1 = op1 / 2;
        i++;
    }
    reverse(binaryNum.rbegin(),binaryNum.rend());
    for(i=0;i<binaryNum.size();i++)
    {
        if(binaryNum[i]==1)
           binaryNum[i]=0;
        else 
           binaryNum[i]=1;
    }
    // for(i=0;i<binaryNum.size();i++)
    //   cout<<binaryNum[i];
    //reverse(binaryNum.rbegin(),binaryNum.rend());
    int decimal = 0,rem,n=binaryNum.size();
    int k=0;
    while(n!=0)
    {   
        decimal=decimal+binaryNum[n-1]*pow(2,k);
        ++k;
        n--;    
    }
    registers[0] =convToHexa(decimal);  
}




