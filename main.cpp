#include "headerFiles/master.hpp"


class emulator8085{
    private:
    map<string,string> memory;
    vector<string> sequence;
    string pc;
    string start;
    string registers[7];
    bool flag[5];
   
    public:
     emulator8085(){
        start="";
        pc="";
        registers;
        for(int i=0;i<7;i++)
            registers[i]="00";
        for(int i=0;i<7;i++)
            flag[i]=false;
        
    }

    void input()
    {
        cout<<"Enter the starting address:";
        cin>>start;
        string line;
        ifstream file("file.txt");

        int lineNo=0;
        char arr[4]={""};

        while(!file.eof())
        {
            getline(file,line);
            getAddress(line,pc,arr);
            pc=arr;
            sequence.push_back(pc);
            memory[pc]=line;
        }
    }

    
    // void evaluate(memory,sequence,address,pc, register, evaluate)
    // {

    // }


};

int main()
{

    emulator8085 instance;
    instance.input();


    // instance.evaluate();


}