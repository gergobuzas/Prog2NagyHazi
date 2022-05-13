/**
 * @file menu.hpp
 * @author Gergo Buzas (buzasgergo0615@gmail.com)
 * @brief The "GUI" of the program. This handles the console text and the input-outputs
 * @version 0.1
 * @date 2022-05-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include "string5.h"

using std::cout;
using std::cin;
using std::endl;

#ifndef MAIN_CPP_MENU_H
#define MAIN_CPP_MENU_H

void clearscreen() {
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

/**
 * @brief Handles the whole interface (text/console-based)
 * 
 * @param filmtomb the object where the data management is happening
 */
void menu(FilmTar &filmtomb) {
    bool valtozasVolt = false;
    char input;
    bool exit = false;

    while (!exit) {
        clearscreen();
        cout << "Udvozoljuk a Filmtar adatbazisban\n\n" << endl;
        cout << "1 - Uj film hozzaadasa\n" << endl;
        cout << "2 - Film torlese az adatbazisbol\n" << endl;
        cout << "3 - Filmek lekerdezese\n" << endl;
        cout << "Q - Kilepes\n" << endl;
        cin >> input;
        cin.clear();
        switch (input) {

            case '1':
                clearscreen();
                filmtomb.adatbazisHozzaadFelhasznalo(valtozasVolt);
                break;

            case '2':
                clearscreen();
                filmtomb.adatbazisTorolFelhasznalo(valtozasVolt);
                break;

            case '3':
                clearscreen();
                filmtomb.osszesformazottKiir();
                cin >> input;
                cin.clear();
                clearscreen();
                break;

            case 'q':
            case 'Q':
                clearscreen();
                cout << "Biztos ki szeretne lepni a programbol?(Y/N) (I/N)\n" << endl;
                while (input != 'Y' and input != 'y' and input != 'i' and input != 'I' and input != 'n' and input != 'N'){
                    cin >> input;
                    cin.clear();
                }
                if (input == 'Y' or input == 'y' or input == 'I' or input == 'i') {
                    exit = true;
                    break;
                } else if (input == 'n' or input == 'N')
                    clearscreen();
                break;

            default:
                clearscreen();
                break;
        }

        if (exit and valtozasVolt) {
            input = 0;
            cout << "Szeretne menteni az adatbazisban vegrehajtott valtoztatasokat veglegesen? (Y/N) (I/N)" << endl;
            while (input != 'y' and input != 'Y' and input != 'i' and input != 'I' and input != 'n' and input != 'N') {
                cin >> input;
                cin.clear();
            }
            if (input == 'Y' or input == 'y' or input == 'i' or input == 'I') {
                filmtomb.adatbazisMentes("DokumentumFilm.txt");
                filmtomb.adatbazisMentes("CsaladiFilm.txt");
            } else {
                cout << "Nem tortent modositas a txt fajlokban. A modositasok elvetve.\n A bezarashoz adjon input betut!" << endl;
                cin >> input;
                cin.clear();
            }
        }
    }
}

#endif //MAIN_CPP_MENU_H
