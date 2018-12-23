#include <iostream>
#include "func.h"
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
	char * filename = "test.txt";
	makeMass(); 
	if (massChek == true){
		vivod_v_cmd(filename);
		dobavl(filename, "111");
		vivod_v_cmd(filename);
		plus_str(filename, "n_str", 3); //
		vivod_v_cmd(filename);
		del(filename, 4); //
		vivod_v_cmd(filename);
		podsrtoka(filename, "ij"); //
		valueFStrok();
	}else{
		cout << "mass didnt iniciliz";}
    return 0;
}