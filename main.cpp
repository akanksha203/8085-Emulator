#include "header files/master.hpp"

class emulator8085{
    private:
    map<string,string> Memory;
    vector<string> sequence;
    int pc;
    string registers[7];
    bool flag[5];
    
    public:
    void input(){
        string line;
        ifstream file("file.txt");
        while(!file.eof())
        {
            getline(file,line);
            sequence.push_back(line);
        }

    for(int i=0;i<sequence.size();i++)
    cout<<sequence[i]<<endl;
    }

};

int main()
{
    emulator8085 instance;
    instance.input();

}