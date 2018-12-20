#include <iostream>
#include "func.h"
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
	makeMass(); 
	if (massChek == true){
		char * filename = "test.txt";
		vivod_v_cmd(filename);
		dobavl(filename, "adsjop");
		vivod_v_cmd(filename);
		plus_str(filename, "ijads", 3);
		vivod_v_cmd(filename);
		del(filename, 4);
		vivod_v_cmd(filename);
		podsrtoka(filename, "ij");
	}else{cout << "mass didnt iniciliz";}
    return 0;
}