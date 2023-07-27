#ifndef _FUNCTION_H
#define _FUNCTION_H

string addressCalculate(string ,vector<int> &);
int opcodeFetch(string );
int hexaToDecimal(string);
string convToHexa(int);
bool validRegisterPair(string);
bool validAddress(string);
bool ishexa(char);
string hexsum(string,string,bool[]);
string hexsub(string,string);
string hexsum16(string,string);
string hexsub16(string,string);
bool validRegister(string);
string getAddress(string , string);
void evaluate(vector<string>,map<string,string>,string [],bool [],string ,string);
void SET(string ,string,map<string,string> &);
void GET(string,map<string,string> &);



#endif