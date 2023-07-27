#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"

string hexsub16(string arg1, string arg2)
{
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
