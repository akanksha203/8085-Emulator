
#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"
bool validRegisterPair(string reg)
{
    if(reg=="B"||reg=="D"||reg=="H"||reg=="M")
    return true;
    else
    return false;
}