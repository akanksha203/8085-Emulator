#ifndef _FUNCTION_H
#define _FUNCTION_H

string addressCalculate(string ,vector<int> &);
int opcodeFetch(string );
int hexaToDecimal(string);
string convToHexa(int);
bool validRegisterPair(string);
bool validAddress(string);
bool ishexa(char);
bool validRegister(string);
string getAddress(string , string);
void evaluate(vector<string>,map<string,string>,string [],bool [],string ,string);



#endif