#include <cstdlib>
#include <cstring>
#include <iostream>
#include "func.h"
#include <cstdlib>
#include <fstream>

using namespace std;

bool massChek = false;

int massSize = 500;
char **mass = new char*[massSize];
bool makeMass(){ //pls do me
	for (int i = 0; i < massSize; i++){
		mass[i] = new char[massSize];
	}
	
	massChek = true;
}

/*
int getMassSize() {

}
*/

char** resizeMass(){
	int n_massSize = 2 * massSize;
	char **n_mass = new char*[n_massSize];
	
	for (int i = 0; i < massSize; i++){
		n_mass[i] = new char[n_massSize];
		strcpy(n_mass[i], mass[i]); 
		delete [] mass[i];
	}
	delete [] mass;
	
	return n_mass;
}

void vivod_v_cmd(char * filename){
    fstream f;
    f.open(filename, ios::in);
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
		if(i == massSize-1){
			mass = resizeMass();
		}
        fi->getline(mass[i],massSize);
        i++;
    }
    return i;
}

void dobavl(char * filename, char slovo[]){
    fstream fi;
    fi.open(filename, ios::app);
    fi << slovo;
    fi.close();
}

void del(char * filename, int n){
    fstream fi;                                      //n - to chto nado del
    fi.open(filename);                             //i - kol-vo vsex strok
    int i = add_m(&fi); //add file info to mass      //j - chetchik dla mass
    int j(0);
    fi.close();
    fi.open(filename, ios::trunc | ios::out);
    while(j != i-1){
        if(j+1 == n)
            j++;
        fi << mass[j] << endl;
        j++;
    }
}

void plus_str(char * filename, char str[], int n){
    fstream fi;                                      //n - to chto nado del
    fi.open(filename);                             //i - kol-vo vsex strok
    int i = add_m(&fi); //add file info to mass      //j - chetchik dla mass
    int j(0);
    fi.close();
    fi.open(filename, ios::trunc | ios::out);
    while(j+1 != i){
        if(j+1 == n){
            fi << str;
            fi << endl;
        }
        fi << mass[j] << endl;
        j++;
    }
}

void podsrtoka(char * filename, char str[]){
    fstream fi;
    fi.open(filename);
    int countOfStrok = add_m(&fi);
    int sizeOfJopa = strlen(str);
    char *buffer = NULL;
    for(int i = 0; i < countOfStrok; i++) {
        buffer = strstr(mass[i], str);
        if(buffer == NULL) {
            cout << "Podstroka not found" << endl;
        } 
        else {
            cout << mass[i] << endl;
        }
    }    
}
