//
// Created by buzas on 2022. 05. 12..
//
#include <iostream>
#include "fstream"
#include "string5.h"
#include "filmtar.h"
#include <cstring>
#include "conio.h"

using std::cout;
using std::cin;
using std::endl;


void FilmTar::adatbazisBeolvas(const char *fajlNev){
    std::ifstream myFile;
    myFile.open(fajlNev);
    if (myFile.fail()){
        throw("Nem sikerult a fajl megnyitasa");
    }
    unsigned int dbAdat;
    unsigned int korhatar;
    unsigned int kiadEv;
    unsigned int lejatszIdo;
    unsigned int id;
    String filmCim, leiras, kategoria;


    myFile >> dbAdat;
    for (int i = 0; i < dbAdat; ++i) {
        myFile >> id;
        myFile >> filmCim;
        myFile >> lejatszIdo;
        myFile >> kiadEv;
        myFile >> kategoria;
        if (kategoria == "Dokumentumfilm"){
            myFile >> leiras;
            DokumentumFilm* hozzaadando = new DokumentumFilm (id, filmCim, lejatszIdo, kiadEv, kategoria, leiras);
            adatbazisHozzaad(hozzaadando);
        }
        else if (kategoria == "Csaladifilm"){
            myFile >> korhatar;
            CsaladiFilm* hozzaadando = new CsaladiFilm (id, filmCim, lejatszIdo, kiadEv, kategoria, korhatar);
            adatbazisHozzaad(hozzaadando);
        }
    }
    myFile.close();
}



void FilmTar::adatbazisHozzaad(Film *ujFilm) {
    Film** ujFilmLista = new Film*[meret+1];
    for (unsigned int i = 0; i < meret; ++i) {
        ujFilmLista[i] = filmLista[i];
    }
    delete[] filmLista;
    ujFilmLista[meret++] = ujFilm;
    filmLista = ujFilmLista;
}



void FilmTar::adatbazisHozzaadFelhasznalo(bool& valtozasVolt) {
    unsigned int lejatszIdo, kiadEv, kategoria, korhatar;
    String cim(""), leiras("");

    char input = 0;

    cout << "Uj film hozzaadasa\n\n\n" << endl;


    cout << "Adjon meg egy cimet" << endl;
    cin >> cim;
    for (int i = 0; i < meret; ++i) {
        if(filmLista[i]->getCim() == cim) {
            cout << "\nIsmetlodo filmcim!" << endl;
            cout << "A folytatashoz nyomjon egy gombot!...\n" << endl;
            input = getch();
            return;
        }
    }
    cout << "Adjon meg egy lejatszasi idot" << endl;
    cin >> lejatszIdo;
    cout << "Adjon meg egy kiadasi evet" << endl;
    cin >> kiadEv;
    cout << "Adjon meg egy kategoriat\n1 - Dokumentumfilm\n2 - Csaladifilm" << endl;
    kategoria = getch();

    if (kategoria == '1') {
        cout << "Adja meg a dokumentumfilm leirasat" << endl;
        cin >> leiras;

        cout << "\n\nAz On altal megadott adatok:\n" << endl;
        cout << "Cim: " << cim << endl;
        cout << "Lejatszasi ido: " << lejatszIdo << endl;
        cout << "Kiadasi ev: " << kiadEv << endl;
        cout << "Kategoria: Dokumentumfilm" << endl;
        cout << "Leiras: " << leiras << endl;
        cout << "\n\n Szeretne menteni az adatbazisba a megadott adatokat? (Y/N) (I/N)" << endl;


        while (input != 'y' and input != 'Y' and input != 'i' and input != 'I' and input != 'n' and input != 'N') {
            input = getch();
        }
        if (input == 'Y' or input == 'y' or input == 'i' or input == 'I') {
            DokumentumFilm *ujFilm = new DokumentumFilm(meret + 1, cim, lejatszIdo, kiadEv, "Dokumentumfilm", leiras);
            adatbazisHozzaad(ujFilm);
            valtozasVolt = true;
            cout << "\n\nA film hozza lett adva az adatbazishoz!\nA folytatashoz nyomjon le egy gombot..." << endl;
        }
        if (input == 'n' or input == 'N') {
            cout << "\n\nA film nem lett hozzaadva az adatbazishoz!\nA folytatashoz nyomjon le egy gombot..." << endl;
        }
        input = getch();
    }

    if (kategoria == '2') {
        cout << "Adja meg a csaladifilm korhatarat" << endl;
        cin >> korhatar;
        cout << "\n\nAz On altal megadott adatok:\n" << endl;
        cout << "Cim: " << cim << endl;
        cout << "Lejatszasi ido: " << lejatszIdo << endl;
        cout << "Kiadasi ev: " << kiadEv << endl;
        cout << "Kategoria: Dokumentumfilm" << endl;
        cout << "Korhatar: " << korhatar << endl;
        cout << "\n\n Szeretne menteni az adatbazisba a megadott adatokat? (Y/N) (I/N)" << endl;


        while (input != 'y' and input != 'Y' and input != 'i' and input != 'I' and input != 'n' and input != 'N') {
            input = getch();
        }
        if (input == 'Y' or input == 'y' or input == 'i' or input == 'I') {
            CsaladiFilm *ujFilm = new CsaladiFilm(meret + 1, cim, lejatszIdo, kiadEv, "Csaladifilm", korhatar);
            adatbazisHozzaad(ujFilm);
            valtozasVolt = true;
            cout << "\n\nA film hozza lett adva az adatbazishoz!\nA folytatashoz nyomjon le egy gombot..." << endl;
        }
        if (input == 'n' or input == 'N') {
            cout << "\n\nA film nem lett hozzaadva az adatbazishoz!\nA folytatashoz nyomjon le egy gombot..."
                 << endl;
        }
        input = getch();
    }
}



void FilmTar::adatbazisTorol(String& torlendoFilm){
    Film** ujFilmLista = new Film*[meret-1];
    unsigned int idx = 0;
    for (int i = 0; i < meret; ++i) {
        if (filmLista[i]->getCim() != torlendoFilm) {
            ujFilmLista[idx++] = filmLista[i];
        }
    }
    meret--;
    delete[] filmLista;
    filmLista = ujFilmLista;
}

void FilmTar::adatbazisTorolFelhasznalo(bool& valtozasVolt){
    String torlendo("");
    bool talalat = false;
    char input = 0;

    cout << "Adja meg a torlendo film cimet" << endl;
    cin >> torlendo;
    for (int i = 0; i < meret; ++i) {
        if (filmLista[i]->getCim() == torlendo) {
            talalat = true;
            cout << "\n\nKeresett film megtalalva. Adatai:\n\n" << endl;
            filmLista[i]->formazottKiir(cout);
            cout << "\n\nBiztos szeretne torolni az adatbazisbol? (Y/N) (I/N)" << endl;

            while (input != 'y' and input != 'Y' and input != 'i' and input != 'I' and input != 'n' and input != 'N') {
                input = getch();
            }
            if (input == 'Y' or input == 'y' or input == 'i' or input == 'I') {
                adatbazisTorol(torlendo);
                valtozasVolt = true;
                cout << "\n\nA film torolve lett az adatbazisbol\nA folytatashoz nyomjon meg egy gombot..." << endl;
            }
            if (input == 'N' or input == 'n') {
                cout << "\n\nA film nem lett torolve az adatbazisbol\nA folytatashoz nyomjon meg egy gombot..." << endl;
            }
            input = getch();
            return;
        }
    }
    if (!talalat) {
        cout << "\n\nIlyen film nem szerepel az adatbazisban\nA folytatashoz nyomjon meg egy gombot..." << endl;
        input = getch();
    }
}



void FilmTar::adatbazisMentes(const char *fajlNev) {
    std::ofstream myFile;
    myFile.open(fajlNev);
    if (myFile.fail()){
        throw("Nem sikerult a fajl megnyitasa");
    }

    unsigned int kategoriadb = 0;
    for (int i = 0; i < meret; ++i){
        if (strcmp(fajlNev, "DokumentumFilm.txt") == 0){
            if (filmLista[i]->getKategoria() == "Dokumentumfilm")
                kategoriadb++;
        }
        else if (strcmp(fajlNev, "CsaladiFilm.txt") == 0){
            if (filmLista[i]->getKategoria() == "Csaladifilm")
                kategoriadb++;
        }
    }

    myFile << kategoriadb;
    myFile << "\n";
    for (int i = 0; i < meret; ++i) {
        if (!strcmp(fajlNev, "DokumentumFilm.txt") && filmLista[i]->getKategoria() == "Dokumentumfilm"){
            filmLista[i]->kiir(myFile);
        }
        else if (!strcmp(fajlNev, "CsaladiFilm.txt") && filmLista[i]->getKategoria() == "Csaladifilm"){
            filmLista[i]->kiir(myFile);
        }
    }
    myFile.close();
}

void FilmTar::osszesformazottKiir(){
    for (int i = 0; i < meret; ++i) {
        filmLista[i]->formazottKiir(std::cout);
        std::cout << std::endl;
    }

    cout << "\n\nOsszesen " << meret << "db film.\n\nA folytatashoz nyomjon le egy gombot..." << endl;
}

