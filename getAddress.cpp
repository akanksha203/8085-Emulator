#include "headerFiles/master.hpp"
#include  "headerFiles/function.hpp"
#include <sstream>

string getAddress(string x, string pc)
{
        int pcValue=hexaToDecimal(pc);
        // vector<string> arr;
        stringstream statement(x);
        string temp;
        getline(statement,temp,' ');
        // arr.push_back(temp);
        // while(getline(statement,temp,','))
        // {
        //         arr.push_back(temp);
        // }
        
        int count=opcodeFetch(temp);
        cout<<count<<endl;;
        
        pcValue+=count;
        return convToHexa(pcValue);

        


}