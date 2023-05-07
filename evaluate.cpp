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
        cout << command<<endl;
        if (command == "MOV")
        {
            MOV(arr[1], arr[2], registers, memory);
            pc = sequence[++i];
        }
        else if (command == "LDA")
        {
            string address = arr[1];
            if (memory.find(address) != memory.end())
            {
                registers[0] = memory[address];
            }
            pc = sequence[++i];
            //cout<<registers[0];
        }
        else if (command == "ADD")
        {
            string reg = arr[1];
            ADD(reg, registers, memory);
            pc = sequence[++i];
        }
        else if (command == "STA")
        {
            string address = arr[1];
            STA(address, registers, memory);
            pc = sequence[++i];
        }
        else
        {
            // Handle unknown command
            pc = sequence[++i];
        }
    }
}
