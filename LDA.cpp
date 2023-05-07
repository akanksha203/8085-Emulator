#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"
using namespace std;
void LDA(string arg,string registers[],map<string ,string>memory)
{
    int l=arg.length();
    if(l==4)
    {
       if( validAddress(arg))
       {
        registers[0]=memory[arg];
    }
    else{
        cout<<"invalid address";
    }
}
else
{
    cout<<"invlaid arg";
}
}