#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"

string JC(bool flag[],string pos)
{
    
    if(flag[0]==true)
      return pos;
}


///           JNC

string JNC(bool flag[],string pos)
{
    
    if(flag[0]==false)
      return pos;

}


string JNZ(bool flag[],string pos)
{
    
    if(flag[6]==false)
      return pos;
}

string JZ(bool flag[],string pos)
{
    
    if(flag[6]==true)
      return pos;
}