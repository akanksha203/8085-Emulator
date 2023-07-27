#include "headerFiles/master.hpp"
#include  "headerFiles/function.hpp"
string convToHexa(int number) {
    string hexa = "";

    if (number < 0) {
        number = -number; 
        number = (1 << 16) - number;  
    }

    while (number != 0) {
        int rem = number % 16;
        if (rem > 9)
            hexa = char(rem - 10 + 'A') + hexa;
        else
            hexa = char(rem + '0') + hexa;
        number /= 16;
    }

    while (hexa.size() < 4) {
        hexa = "0" + hexa;
    }

    return hexa;
}

