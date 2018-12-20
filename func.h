#ifndef __FUNC__
#define __FUNC__

#include <fstream>
extern bool massChek;
bool makeMass();
void vivod_v_cmd(char * filename);
void dobavl(char * filename, char slovo[]);
void del(char * filename, int n);
void plus_str(char * filename, char str[], int n);
void podsrtoka(char * filename, char str[]);

#endif