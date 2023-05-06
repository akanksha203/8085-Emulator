#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"
#include "headerFiles/arithmatic.hpp"
#include "headerFiles/loadAndStore.hpp"
#include "headerFiles/logical.hpp"

void evaluate(vector<string> sequence,map<string,string> memory,string registers[],bool flag[],string start,string pc)
{
    pc=start;
    int i=0;
    while(i!=sequence.size())
    {
        vector<string> arr;
        string currentCommand=memory[pc];
        stringstream statement(currentCommand);
        string temp="";
        getline(statement,temp,' ');
        arr.push_back(temp);
        while(getline(statement,temp,','))
        {
                arr.push_back(temp);
        }

        string command=arr[0];
        switch(command)
        {
            case "MOV":
                MOV(arr[1],arr[2], registers);
                pc=sequence[++i];
            break;

            case "MVI":
                MVI(arr[1],arr[2],registers);
                pc=sequence[++i];
            break;

            case "ADD":
                ADD(arr[1],registers,memory);
                pc=sequence[++i];
            break;

            case "ADI":
                pc=sequence[++i];

            break;

            case "SUB":
                SUB(arr[1],registers,memory);
                pc=sequence[++i];

            break;

            case "SUI":
                pc=sequence[++i];

            break;

            case "JNC":
            break;

            case "JC":
            break;

            case "DCR":
                pc=sequence[++i];

            break;
            
            case "INR":
                INR(registers);
                pc=sequence[++i];
            break;
            
            case "INX":
                INX(registers);
                pc=sequence[++i];
            break;
            
            case "DCX":
                DCX(registerss);
                pc=sequence[++i];
            break;
            
            case "CMA":
                pc=sequence[++i];
            break;
            
            case "CMP":
                pc=sequence[++i];
            break;
            
            case "XCHG":
                XCHG(registers);
                pc=sequence[++i];
            break;
            
            case "DAD":
                pc=sequence[++i];
            break;
            
            case "STAX":
                pc=sequence[++i];
            break;
            
            case "STA":
                pc=sequence[++i];
            break;
            
            case "SET":
                pc=sequence[++i];
            break;
            
            case "LXI":
                pc=sequence[++i];
            break;
            
            case "LDA":
                pc=sequence[++i];
            break;
            
            case "SHLD":
                pc=sequence[++i];
            break;
            
            case "LHLD":
                pc=sequence[++i];
            break;
            
            case "JMP":
            break;
            
            case "JZ":
            break;
            
            case "JNZ":
            break;
            
            case "DCX":
                DCX(registers);
                pc=sequence[++i];
            break;

            default:
            break;
        }
    }

}