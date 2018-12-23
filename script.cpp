#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
    fstream f("test.txt");
    for(int i = 0; i != 499; i++){
        f << i << endl;
    }
    return 0;
}