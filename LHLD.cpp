// #include "headerFiles/master.hpp"
// #include "headerFiles/function.hpp"
#include<iostream>
#include<map>
#include<string.h>
#include<string>
using namespace std;
bool validAddress(string str)
{
    bool flag=false;
    int len=str.length();
    for(int i=0;i<len;i++)
    {
        if((str[i]>='0'&&str[i]<='9')||(str[i]>='A'&&str[i]<='F'))
    flag=true;
    else
    flag=false;
    }
    return flag;
}
void LHLD(string add,string registers[],map<string,string>&memory)
{
int l=add.size();
if(l==4)
{
if (validAddress(add))
{
    registers[6]=memory[add];
    registers[5]=memory[add+"1"];
     cout<<"h"<<registers[5]<<endl;
    cout<<registers[6]<<endl;

}
else
{
    cout<<"invalid";
    exit(0);
}
}
else
{
cout<<"not a valid address";
exit(0);
}
}
int main()
{
map<string,string>memory;
string registers[7];
//registers[0]="90";
memory["2000"]="78";
memory["2001"]="1";
//cout<<memory["2000"]<<endl;

LHLD("2000","2001",registers,memory);
// cout<<registers[5]<<endl;
// cout<<registers[6]<<endl;
return 0;
}
