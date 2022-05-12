
//
// Created by buzas on 2022. 05. 12..
//
#include <iostream>
#include "conio.h"

using std::cout;
using std::cin;
using std::endl;

#ifndef MAIN_CPP_MENU_H
#define MAIN_CPP_MENU_H

void clear() {
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined (__APPLE__)
    system("clear");
#endif
}

void menu(){
    bool exit = false;
    char menupont;
    while (!exit){
        cout << "Udvozoljuk a Filmtar adatbazisban\n\n" << endl;
        cout << "1 - Uj film hozzaadasa\n" << endl;
        cout << "2 - Film torlese az adatbazisbol\n" << endl;
        cout << "3 - Filmek lekerdezese\n" << endl;
        cout << "Q - Kilepes\n" << endl;
        menupont = getch();
        switch(menupont){
            case '1':
                clear();
                break;
            case '2':
                clear();
                break;
            case '3':
                clear();
                break;
            case 'q':
            case 'Q':
                clear();
                cout << "Biztos ki szeretne lepni a programbol?(Y/N)\n" << endl;
                menupont=getch();
                if(menupont == 'Y' or menupont == 'y'){
                    exit = true;
                    break;
                }
                else if(menupont == 'n' or menupont == 'N')
                    clear();
                    break;
        }
    }
}

#endif //MAIN_CPP_MENU_H
