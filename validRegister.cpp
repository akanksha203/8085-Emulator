#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"

bool validRegister(string reg)
{
if(reg=="A"||reg=="B"||reg=="C"||reg=="D"||reg=="E"||reg=="H"||reg=="L")
return true;
else
return false;
}