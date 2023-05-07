#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"

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
        for(int i=0;i<7;i++)
            registers[i]="00";
        for(int i=0;i<7;i++)
            flag[i]=false;
        
    }

    void input()
    {
        cout<<"Enter the starting address:";
        cin>>start;
        pc=start;

        string line;
        ifstream file("file.txt");

        int lineNo=0;
        char arr[4]={""};

        while(!file.eof())
        {
            getline(file,line);
            sequence.push_back(pc);
            memory[pc]=line;
            pc=getAddress(line,pc);
            // if(line=="HLT")
            //     break;
        }
    }
   void output() {
    for (int i = 0; i < sequence.size(); i++) {
        cout << sequence[i] << ": " << memory[sequence[i]] << endl;
    }
}


    
    void evaluates()
    {
       evaluate(sequence,memory,registers,flag,start,pc);
     }

};

int main()
{

    emulator8085 instance;
    instance.input();

    
    instance .evaluates();
    instance.output();

}