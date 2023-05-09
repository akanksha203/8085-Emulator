#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"

///////////JC
string JC(string address, string pc, bool flag[], vector<string> sequence)
{
    
     if (flag[0] == true) {
        for (int i = 0; i < sequence.size(); i++) {

            if (address == sequence[i]) {
                pc = sequence[i]; 
                break;
            }
        }
    }
 
    return pc;


}








//////////////JNC
string JNC(string address, string pc, bool flag[], vector<string> sequence) {
    if (flag[0] == false) {
        for (int i = 0; i < sequence.size(); i++) {

            if (address == sequence[i]) {
                pc = sequence[i]; 
                break;
            }
        }
    }
 
    return pc;
}










///////////////JZ
string JZ(bool flag[],string pos)
{
    
    if(flag[6]==true)
      return pos;


}










/////////////////JNZ
string JNZ(bool flag[],string pos)
{
    
    if(flag[6]==false)
      return pos;


}