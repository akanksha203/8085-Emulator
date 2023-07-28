#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"

string hexsub(string arg1, string arg2, bool flag[]) {
    int op1 = hexaToDecimal(arg1);
    int op2 = hexaToDecimal(arg2);
    int diff = op1 - op2;
    int borrow = 0; 

    if (op1 < op2) {
        borrow = 1; 
    }

    int lowerNibbleOp1 = op1 & 0x0F;
    int lowerNibbleOp2 = op2 & 0x0F;
    int lowerNibbleDiff = diff & 0x0F;
    if(borrow || (lowerNibbleDiff > lowerNibbleOp1))
        flag[4]=true;

    bitset<8> dataInBinary(diff);
    int parity = dataInBinary.count();
    if(parity==0)
		flag[2]=true;
	else if(parity%2==0)
		flag[2]=true;
	else if(parity%2==1)
		flag[2]=false;
    
    if (diff == 0)
        flag[6] = true;
    else
        flag[6] = false;
    flag[7] = dataInBinary[7];
    

    flag[0] = diff < 0;

    string res = convToHexa(diff);
    cout << "carry is " << flag[0] << endl;
    cout << "parity is " << flag[2] << endl;
    cout << "auxiliary carry is " << flag[4] << endl;
    cout << "zero is " << flag[6] << endl;
    cout << "sign is " << flag[7] << endl;
    if (res.length() == 5) {
        res = res.substr(1);
    }

    return res;
}
