#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"

void LXI(string registers[], map<string,string>memory ,string operand)
{
    string reg = operand.substr(0,2);
    string Value = operand.substr(2,4);

    if (reg== "B") {
        registers[2] = Value.substr(0,2);
        registers[1] = Value.substr(2,2);
    } else if (reg == "D") {
        registers[4] = Value.substr(0,2);
        registers[3] = Value.substr(2,2);
    } else if (reg == "H") {
        registers[6] = Value.substr(0,2);
        registers[5] = Value.substr(2,2);
    } else if (reg == "S") {
        registers[8] = Value.substr(0,2);
        registers[7] = Value.substr(2,2);
    }
    //substr(start,length);
  
    //A0 B1 C2 D3 E4 H5 L6
}
