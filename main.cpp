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


<<<<<<< HEAD
    
    void evaluates()
    {
       evaluate(sequence,memory,registers,flag,start,pc);
     }

=======
    void eval()
    {
        evaluate(sequence, memory, registers, flag, start, pc);
    }
>>>>>>> b0b5697b9cc8c4ac195014987800bb75c801cd4c

};

int main()
{

    emulator8085 instance;
    instance.input();
<<<<<<< HEAD
    instance.output();
    instance .evaluates();

=======
    instance.eval();
>>>>>>> b0b5697b9cc8c4ac195014987800bb75c801cd4c
    // instance.evaluate();


}