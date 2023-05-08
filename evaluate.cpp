#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"
#include "headerFiles/arithmatic.hpp"
#include "headerFiles/loadAndStore.hpp"
#include "headerFiles/logical.hpp"
#include<sstream>

void evaluate(vector<string> sequence, map<string, string> memory, string registers[], bool flag[], string start, string pc)
{
    pc = start;
    int i = 0;
    while (i != sequence.size())
    {
        vector<string> arr;
        string currentCommand = memory[pc];
        stringstream statement(currentCommand);
        string temp = "";
        getline(statement, temp, ' ');
        arr.push_back(temp);
        while (getline(statement, temp, ','))
        {
            arr.push_back(temp);
        }

        string command = arr[0];
       // cout << command<<endl;
        if (command == "MOV")
        {
           // cout<<arr[1]<<" "<<arr[2];

            MOV(arr[1], arr[2], registers, memory);
            pc = sequence[++i];
            //cout<<registers[1]<<endl;
        }
        else if (command == "LDA")
        {
            string reg = arr[1];
            LDA(reg, registers, memory);
            pc = sequence[++i];
            // cout<<"Accumulator:"<<registers[0]<<endl;
        }
        else if (command == "MVI")
        {
            MVI(arr[1],arr[2], registers, memory);
            pc = sequence[++i];
            
        }
        else if (command == "ADD")
        {
            string reg = arr[1];
            ADD(reg, registers, memory);
            pc = sequence[++i];
           //cout<<registers[0]<<endl;
        }

        else if (command == "SUB")
        {
            string reg = arr[1];
            SUB(reg, registers, memory);
            pc = sequence[++i];
           // cout<<registers[0]<<endl;
        }
        else if(command == "INR")
        {
            INR(arr[1],registers);
            pc = sequence[++i];
            cout<<"after increment:"<<registers[0]<<endl;
        }
        else if (command == "STA")
        {
            string address = arr[1];
            STA(address, registers, memory);
            pc = sequence[++i];
            cout<<"value at "<<arr[1]<<":"<<memory[arr[1]]<<endl;
        }
        else if(command == "JNC")
        {
            string loop;
            string address = arr[1];
            loop=JNC(address, pc, flag);
            pc=loop;
            pc=sequence[++i];
            //pc = sequence[++i];
        }
        else if(command == "HLT")
        {
            break;
        }
        else
        {
            // Handle unknown command
            pc = sequence[++i];
        }
    }
}
