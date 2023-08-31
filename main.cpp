#include "headerFiles/master.hpp"
#include "headerFiles/function.hpp"

class emulator8085{
    private:
    map<string,string> memory;
    vector<string> sequence;
    string pc;
    string start;
    string registers[7];
    bool flag[8];
    int breakpoint;
    int step;
   
    public:
     emulator8085(){
        start="";
        pc="";
        for(int i=0;i<7;i++)
            registers[i]="00";
        for(int i=0;i<8;i++)
            flag[i]=false;
        breakpoint=0;
        step=0;
        
    }

    void input()
    {
        cout << "Enter the starting address: ";
        cin >> start;
        cout<<endl;
        pc = start;

        string line;
        ifstream file("file.txt");

        while (!file.eof())
        {
            getline(file, line);
            sequence.push_back(pc);
            memory[pc] = line;
            pc = getAddress(line, pc);
        }
        breakpoint=sequence.size();
        pc=start;
    }

    void output()
    {
        for (int i = 0; i < sequence.size(); i++)
        {
            cout << sequence[i] << ": " << memory[sequence[i]] << endl;
        }
    
    }

    void evaluates()
    {
        pc=start;
       pc=evaluate(sequence,memory,registers,flag,start,pc,sequence.size());
       cout<<registers[0]<<endl;
       cout<<flag[0];
       step=0;
    }

    void help()
    {
        cout<<"\nEnter b or break to set a breakpoint"<<endl;
        cout<<"Enter r or run to execute the program till the breakpoint"<<endl;
        cout<<"Enter s or step to execute one instruction at a time"<<endl;
        cout<<"Enter p or print to print the value of register"<<endl;
        cout<<"Enter q or quite to exite"<<endl;
        cout<<"Enter help to learn rules"<<endl;
    }

    void run()
    {
        pc=start;
        pc=evaluate(sequence,memory,registers,flag,start,pc,breakpoint);

    }

    void breakpoint_Select()
    {
        cout<<"Enter the line to add breakpoint:";
        cin>>breakpoint;
        breakpoint--;
    }

    void stepExecution()
    {
        pc=evaluate(sequence,memory,registers,flag,start,pc,step+1);
        step++;
    }

    void print()
    {
         cout<<"\n\t\tARCHITECTURE"<<endl;
         cout<<"******************************************************\n";
         cout<<"A       B       C       D       E       H       L"<<endl;
         for(int i=0;i<7;i++)
            cout<<registers[i]<<"\t";
        cout<<endl<<endl;

         cout<<"******************************************************\n";
         cout<<"S       Z       AC      P       C"<<endl;
        
            cout<<flag[7]<<"\t";
            cout<<flag[6]<<"\t";
            cout<<flag[4]<<"\t";
            cout<<flag[2]<<"\t";
            cout<<flag[0]<<"\t";
        
        cout<<endl<<endl;
        cout<<"PC:"<<pc<<endl<<endl;
         cout<<"******************************************************\n";

          cout << "MEMORY LOCATIONS WITH NON-ZERO VALUES:" << endl;
            for (const auto& entry : memory)
            {
                if (entry.first.compare("3000") >= 0 && entry.second != "00")
                {
                    cout << entry.first << ": " << entry.second << endl;
                }
            }
           cout << "******************************************************\n";
    }

};

int main()
{
    cout<<"\nTHIS IS 8085 EMULATOR"<<endl;
    emulator8085 instance;
    instance.input();
    cout<<"*******CODE*******"<<endl;
    instance.output();
    cout<<"\nEnter 1 is you want to evaluate normally\nEnter 2 if you want to use debugger\nEnter 3 or default to exit\n";
    while(true)
    {
        int c;
        cin>>c;
        cout<<endl;
        if(c==1)
        {
            instance.evaluates();
        }
        else if(c==2)
        {
            instance.help();
            while(true)
            {
                string choice;
                cout<<"choice:";
                cin>>choice;
                cout<<endl;

                if(choice=="r"||choice=="run")
                {
                    instance.run();
                }

                else if(choice=="b"||choice=="break")
                {
                    instance.breakpoint_Select();
                }
                
                else if(choice=="s"||choice=="step")
                {
                    instance.stepExecution();
                }

                else if(choice=="p"||choice=="print")
                {
                    instance.print();
                }

                else if(choice=="q"||choice=="quit")
                {
                    break;
                }

                else if(choice=="help")
                {
                    instance.help();
                }
                else
                {
                    cout<<"Enter a valid command or use help"<<endl;
                }
            
            }
        }
        else
            exit(1);
        cout<<"\nEnter 1 is you want to evaluate normally\nEnter 2 if you want to use debugger\nEnter 3 or default to exit\n";
        
    }
  
}