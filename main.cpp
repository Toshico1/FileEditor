#include <iostream>
#include "func.h"
#include <fstream>
using namespace std;

int main(int argc, char* argv[]){
    char * filename = "test.txt";
    vivod_v_cmd(filename);
    dobavl(filename, "adsjop");
    plus_str(filename, "ijads", 3);
    del(filename, 4);
    podsrtoka(filename, "ij");

    return 0;
}
/*
str1
str2
str3
str4
str5
str6
*/

