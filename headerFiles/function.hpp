#ifndef _FUNCTION_H
#define _FUNCTION_H

string addressCalculate(string ,vector<int> &);
void XCHG(string []);
int opcodeFetch(string command);
int hexaToDecimal(string s);
string convToHexa(int number);
void ADD(int reg,string [],map<string,string>);
void SUB(int reg,string [],map<string,string>);
void INR(string []);
void DCR(string []);
void DCX(string []);
void INX(string []);
string getAddress(string line, string pc);



#endif