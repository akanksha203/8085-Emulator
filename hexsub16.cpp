#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"

string hexsub16(string command,string arg1, string arg2, bool flag[])
{
    if(command!="DCX"){
        int op1 = hexaToDecimal(arg1);
        int op2 = hexaToDecimal(arg2);
        int diff = op1 - op2;
        string res = convToHexa(diff);

        if (res.length() > 4)
        {
            res = res.substr(res.length() - 4);
        }

        while (res.length() < 4)
        {
            res = "0" + res;
        }
        int borrow = 0;

        if (op1 < op2) {
            borrow = 1;
        }

        int lowerNibbleOp1 = op1 & 0x000F;
        int lowerNibbleOp2 = op2 & 0x000F;
        int lowerNibbleDiff = diff & 0x000F;
        if(borrow || (lowerNibbleDiff > lowerNibbleOp1))
                flag[4]=true;

        bitset<16> dataInBinary(diff);
        int parity = dataInBinary.count();

        if (parity == 0)
            flag[2] = true;
        else if (parity % 2 == 0)
            flag[2] = true;
        else if (parity % 2 == 1)
            flag[2] = false;

        if (diff == 0)
            flag[6] = true;
        else
            flag[6] = false;
        flag[7] = dataInBinary[15];

        flag[0] = (diff < 0);

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
        int diff = op1 - op2;

        string res = convToHexa(diff);

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
