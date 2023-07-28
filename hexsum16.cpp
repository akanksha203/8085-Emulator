#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"

string hexsum16(string command,string arg1, string arg2, bool flag[])
{
    if(command!="INX"){
        cout<<"WHY HEREE"<<endl;
        int op1 = hexaToDecimal(arg1);
        int op2 = hexaToDecimal(arg2);
        int sum = op1 + op2;

        string res = convToHexa(sum);

        if (res.length() > 4)
        {
            res = res.substr(res.length() - 4);
        }

        while (res.length() < 4)
        {
            res = "0" + res;
        }

        bitset<16> dataInBinary(sum);
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
        flag[7] = dataInBinary[15];
         flag[0]=sum > 0xFFFF;
            
        if(((op1 & 0xFFF) + (op2 & 0xFFF)) > 0xFFF)
            flag[4]=true;
        cout << "carry is " << flag[0] << endl;
        cout << "parity is " << flag[2] << endl;
        cout << "auxiliary carry is " << flag[4] << endl;
        cout << "zero is " << flag[6] << endl;
        cout << "sign is " << flag[7] << endl;
        return res;
    }
    else{
         int op1 = hexaToDecimal(arg1);
        int op2 = hexaToDecimal(arg2);
        int sum = op1 + op2;

        string res = convToHexa(sum);

        if (res.length() > 4)
        {
            res = res.substr(res.length() - 4);
        }

        while (res.length() < 4)
        {
            res = "0" + res;
        }
        return res;
    }
}
