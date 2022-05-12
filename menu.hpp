
//
// Created by buzas on 2022. 05. 12..
//
#include <iostream>
#include "conio.h"
#include "string5.h"

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

void menu(FilmTar& filmtomb){
    //Uj film hozzaadasahoz valtozok
    unsigned int lejatszIdo, kiadEv, kategoria, korhatar;
    String cim(""), leiras("");

    char mentes;

    //Film torlesehez valtozok
    String torlendo("");
    bool torolve = false;

    char menupont;
    bool exit = false;
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
                cout << "Uj film hozzaadasa\n\n\n" << endl;
                cout << "Adjon meg egy cimet" << endl;
                cin >> cim;
                cout << "Adjon meg egy lejatszasi idot" << endl;
                cin >> lejatszIdo;
                cout << "Adjon meg egy kiadasi evet" << endl;
                cin >> kiadEv;
                cout << "Adjon meg egy kategoriat\n1 - Dokumentumfilm\n2 - Csaladifilm" << endl;
                kategoria = getch();
                if (kategoria == '1'){
                    cout << "Adja meg a dokumentumfilm leirasat" << endl;
                    cin >> leiras;
                    clear();
                    cout << "Az On altal megadott adatok:\n" << endl;
                    cout << "Cim: " << cim << endl;
                    cout << "Lejatszasi ido: " << lejatszIdo << endl;
                    cout << "Kiadasi ev: " << kiadEv << endl;
                    cout << "Kategoria: Dokumentumfilm" << endl;
                    cout << "Leiras: " << leiras << endl;
                    cout << "\n\n Szeretne menteni az adatbazisba a megadott adatokat? (Y/N) (I/N)" << endl;
                    mentes = getch();
                    if(mentes == 'Y' or mentes == 'y' or mentes =='i' or mentes == 'I'){
                        DokumentumFilm ujFilm(filmtomb.getMeret() + 1, cim, lejatszIdo, kiadEv, "Dokumentumfilm", leiras);
                        filmtomb.adatbazisHozzaad(&ujFilm);
                        cout << "A film hozza lett adva az adatbazishoz!\nA folytatashoz nyomjon le egy gombot..." << endl;
                    }
                    if(mentes == 'n' or mentes == 'N'){
                        cout << "A film nem lett hozzaadva az adatbazishoz!\nA folytatashoz nyomjon le egy gombot..." << endl;
                    }
                    mentes = getch();
                    clear();
                }
                if(kategoria == '2'){
                    cout << "Adja meg a csaladifilm korhatarat" << endl;
                    cin >> korhatar;
                    clear();
                    cout << "Az On altal megadott adatok:\n" << endl;
                    cout << "Cim: " << cim << endl;
                    cout << "Lejatszasi ido: " << lejatszIdo << endl;
                    cout << "Kiadasi ev: " << kiadEv << endl;
                    cout << "Kategoria: Dokumentumfilm" << endl;
                    cout << "Korhatar: " << korhatar << endl;
                    cout << "\n\n Szeretne menteni az adatbazisba a megadott adatokat? (Y/N) (I/N)" << endl;
                    mentes = getch();
                    if(mentes == 'Y' or mentes == 'y' or mentes =='i' or mentes == 'I'){
                        CsaladiFilm ujFilm(filmtomb.getMeret() + 1, cim, lejatszIdo, kiadEv, "Csaladifilm", korhatar);
                        filmtomb.adatbazisHozzaad(&ujFilm);
                        cout << "A film hozza lett adva az adatbazishoz!\nA folytatashoz nyomjon le egy gombot..." << endl;
                    }
                    if(mentes == 'n' or mentes == 'N'){
                        cout << "A film nem lett hozzaadva az adatbazishoz!\nA folytatashoz nyomjon le egy gombot..." << endl;
                    }
                    mentes = getch();
                    clear();
                }
                break;
            case '2':
                clear();
                cout << "Adja meg a torlendo film cimet" << endl;
                cin >> torlendo;
                for (int i = 0; i < filmtomb.getMeret(); ++i) {
                    if(filmtomb.getFilmLista()[i]->getCim() == torlendo){
                        cout << "\n\nKeresett film megtalalva. Adatai:\n\n" << endl;
                        filmtomb.getFilmLista()[i]->formazottKiir(cout);
                        cout << "\n\nBiztos szeretne torolni az adatbazisbol?" << endl;
                        mentes = getch();
                        if(mentes == 'Y' or mentes == 'y' or mentes =='i' or mentes == 'I'){
                            filmtomb.adatbazisTorol(torlendo);
                        }
                        cout << "A film torolve lett az adatbazisbol" << endl;
                        torolve = true;
                        mentes = getch();
                        clear();
                        break;
                    }
                }
                if(!torolve) {
                    cout << "Ilyen film nem szerepel az adatbazisban\nA folytatashoz nyomjon meg egy gombot..." << endl;
                    mentes = getch();
                    clear();
                }
                break;
            case '3':
                clear();
                for (int i = 0; i < filmtomb.getMeret(); ++i) {
                    filmtomb.getFilmLista()[i]->formazottKiir(cout);
                    cout << endl;
                }
                cout << "\n\nOsszesen " << filmtomb.getMeret() <<"db film.\n\nA folytatashoz nyomjon le egy gombot..." << endl;
                mentes = getch();
                clear();
                break;
            case 'q':
            case 'Q':
                clear();
                cout << "Biztos ki szeretne lepni a programbol?(Y/N) (I/N)\n" << endl;
                menupont = getch();
                if(menupont == 'Y' or menupont == 'y' or menupont == 'I' or menupont == 'i'){
                    exit = true;
                    break;
                }
                else if(menupont == 'n' or menupont == 'N')
                    clear();
                    break;
            default:
                clear();
        }
    }
}

#endif //MAIN_CPP_MENU_H