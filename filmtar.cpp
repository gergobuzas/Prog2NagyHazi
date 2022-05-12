//
// Created by buzas on 2022. 05. 12..
//
#include <iostream>
#include "fstream"
#include "string5.h"
#include "filmtar.h"
#include <cstring>


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
        if (kategoria == "Dokumentum film"){
            myFile >> leiras;
            DokumentumFilm* hozzaadando = new DokumentumFilm (id, filmCim, lejatszIdo, kiadEv, kategoria, leiras);
            adatbazisHozzaad(hozzaadando);
        }
        else if (kategoria == "Csaladi film"){
            myFile >> korhatar;
            CsaladiFilm* hozzaadando = new CsaladiFilm (id, filmCim, lejatszIdo, kiadEv, kategoria, korhatar);
            adatbazisHozzaad(hozzaadando);
        }
        myFile >> filmCim; //hogy a sortoreseket is beolvassa, es utana egybol az uj adattal kezdje
    }
    myFile.close();
}

void FilmTar::adatbazisHozzaad(Film *ujFilm) {
    Film** ujFilmLista = new Film*[meret+1];
    for (int i = 0; i < meret; ++i) {
        *ujFilmLista[i] = *filmLista[i];
        delete filmLista[i];
    }
    delete[] filmLista;
    meret++;
    *ujFilmLista[meret] = *ujFilm;
    *filmLista = *ujFilmLista;
}

void FilmTar::adatbazisTorol(String& torlendoFilm){
    Film** ujFilmLista = new Film*[meret-1];
    unsigned int idx = 0;
    for (int i = 0; i < meret; ++i) {
        if (filmLista[i]->getCim() != torlendoFilm) {
            *ujFilmLista[idx++] = *filmLista[i];
            delete filmLista[i];
        }
        else{
            delete filmLista[i];
        }
    }
    meret--;
    delete[] filmLista;
    *filmLista = *ujFilmLista;
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

void FilmTar::osszesKiir(){
    for (int i = 0; i < meret; ++i) {
        filmLista[i]->kiir(std::cout);
    }
}