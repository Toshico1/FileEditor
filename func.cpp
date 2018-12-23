#include <cstdlib>
#include <cstring>
#include <iostream>
#include "func.h"
#include <cstdlib>
#include <fstream>

using namespace std;

char mass[500][500] = {};

void vivod_v_cmd(){
    fstream f;
    f.open("test.txt", ios::in);
    int i(1);
    char str[256] = {};
    while(!f.eof()){
        f.getline(str,255);
        cout << i << ". " << str << endl;
        i++;
    }
    f.close();
}

int add_m(fstream *fi){
    int i(0);
    while(!fi->eof()){
        fi->getline(mass[i],498);
        i++;
    }
    return i;
}

void dobavl(char slovo[]){
    fstream fi;
    fi.open("test.txt", ios::app);
    fi << slovo;
    fi.close();
}

void del(int n){
    fstream fi;                                      //n - to chto nado del
    fi.open("test.txt");                             //i - kol-vo vsex strok
    int i = add_m(&fi); //add file info to mass      //j - chetchik dla mass
    int j(0);
    fi.close();
    fi.open("test.txt", ios::trunc | ios::out);
    while(j != i-1){
        if(j+1 == n)
            j++;
        fi << mass[j] << endl;
        j++;
    }
}

void plus_str(char str[], int n){
    fstream fi;                                      //n - to chto nado del
    fi.open("test.txt");                             //i - kol-vo vsex strok
    int i = add_m(&fi); //add file info to mass      //j - chetchik dla mass
    int j(0);
    fi.close();
    fi.open("test.txt", ios::trunc | ios::out);
    while(j+1 != i){
        if(j+1 == n){
            fi << str;
            fi << endl;
        }
        fi << mass[j] << endl;
        j++;
    }
}

void podsrtoka(char str[]){
    fstream fi;                                      //n - to chto nado del
    fi.open("test.txt");                             //i - kol-vo vsex strok
    int i = add_m(&fi);
}

