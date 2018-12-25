#include <iostream>
#include <fstream>
#include <cstring>
#include "func.h"
using namespace std;

int valueStrFile(){
    fstream f;
    f.open("test.txt");
    int i = 0;
    char c;
    f.get(c);
    while(!f.eof()){
        if(c == '\n'){
            i++;
        }
        f.get(c);
    }
    return (i+1);
}

void coutFile(char* filename){
    fstream f;
    f.open(filename, ios::in);
    char c;
    int i = 1;
    cout << i << ". "; //для первой строки
    i++;
    f.get(c);
    while(!f.eof()){
        if (c == '\n'){ //счет для всех последующих
           cout << c;
           cout << i << ". "; 
           i++;
        }else{
           cout << c; 
        }
        f.get(c);
    }
    cout << endl;
}
void filePlusStr(char* filename, char* str){
    fstream f;
    f.open(filename, ios::app);
    f << endl;
    f << str;

}
void searchOfStr(char* filename, char* str){

}
void delSomeStr(char* filename, int delStr){
    fstream f;
    f.open(filename);
    ofstream new_f("vrem.txt");
    int allStr = valueStrFile();
   if((delStr != 1) && (delStr != allStr)){
        int i = 1, 
            start = 0,
            finish = 0;
        
        while(i != delStr){ //ищем нашу пред. строчку
            char c;
            f.get(c);    
            if(c == '\n'){ //тут мы на нее вываливаемся
                i++;
            }
            start = f.tellg(); //когда вываливаемся по условию 
                                //сохранияем начала нашей delStr
        }
        char cf;
        while(cf != '\n'){
            f.get(cf);
            finish = f.tellg(); //сохраняем конец нашей delStr
        }
        char cn;
        f.seekg(0, ios::beg);
        f.get(cn); //для коректного вывода(я очень хочу спать 2:10)
        while(!f.eof()){
            if(f.tellg() == start)
                f.seekg(finish, ios::beg);
            new_f << cn;
            f.get(cn);
        }
    }else if(delStr == 1){ //отдельный алгоритм под удаление 1
        char c;
        f.get(c);
        while(c != '\n'){
            f.get(c);
        }
        f.get(c);
        while(!f.eof()){
            new_f << c;
            f.get(c);
        }
    }else if(delStr == allStr){
        int strNow = 1;
        char c;
        f.get(c);
        while(!f.eof()){
            if(strNow != delStr){
                if(c == '\n'){
                    strNow++;
                    if(strNow == delStr)  //да, это костыль, я не могу его фиксануть 2:35
                        break;
                }
                new_f << c;
                f.get(c);  
            }else{
                break;
                }
            }
    }
    int del = remove("test.txt");
    int rena = rename("vrem.txt", filename); 
}


void addSomeStr(char* filename, char* str, int N){
    if(N > valueStrFile() || (N < 1)){
        cout << "Line with this number does not exist. By this you can't add in front of her" << endl;
    }else{
        fstream f;
        f.open(filename);
        ofstream new_f("vrem.txt");
        char c;
        if(N == 1){ //отдельный обработчик для 1 строки (на часа 3)
            new_f << str << endl;
            f.get(c); 
            while(!f.eof()){
            new_f << c;
            f.get(c);
            }
        }else{
            int i = 0; //если я начну обьяснять сейчас что тут происходит, то напишу
            while(i != N-1){//войну и мир, но на самом деле тут все довольно просто
                char c;
                f.get(c);    
                if(c == '\n'){ 
                    i++;
                }
                new_f << c;
            }
            new_f << str << endl;
            f.get(c); 
            while(!f.eof()){ 
                new_f << c;
                f.get(c);
            }
        }
    }
}


void searchOfStr(char* filename, char* str){
    /*char *buffer = NULL;
    buffer = strstr(mass[i], str)*/
}