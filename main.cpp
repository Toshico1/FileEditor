#include <iostream>
#include <fstream>
#include "func.h"
using namespace std;

int main(int argc, char const *argv[])
{
    char *filename = "test.txt";
    //filePlusStr(filename, "test_str");
    //delSomeStr(filename, 5); 
    //addSomeStr(filename, "that's new str!", 5);
    searchOfStr(filename, "tr");
    coutFile(filename);
    return 0;
}




/*Реализовать модуль для работы с файлами.

Функции модуля принимают первым аргументом указатель на FILE.

Модуль должен содержать следующие функции:

1. Вывести файл в консоль, печатая номера строк.

2. Дописать указанную строку в конец файла.

3. Вывести строки (с их номерами), в которых есть указанная подстрока, причем саму подстроку вывести в верхнем регистре.

4. Перезаписать файл, удалив строку с указанным номером.

5. Перезаписать файл, вставив указанную строку перед строкой с указанным номером.

В мейне привести пример использования каждой функции.*/