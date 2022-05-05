//
// Created by buzas on 2022. 04. 24..
//

#include "film.h"
#include "string5.h"

#ifndef SKELETON_FILMTAR_H
#define SKELETON_FILMTAR_H

class FilmTar{
private:
    unsigned int meret = 0;
    Film** filmLista = nullptr;
public:
    FilmTar() = default;

    unsigned int getMeret(){ return meret;}

    Film** getFilmLista() {return filmLista;}

    void adatbazisBeolvas(String fajlNev);

    void adatbazisHozzaad(Film* ujFilm);

    void adatbazisTorol(String torlendoFilm);

    void adatbazisMentes(String fajlNev);

    void osszesKiir();

    ~FilmTar(){
        for (unsigned int i = 0; i < meret; ++i) {
            delete(filmLista[i]);
        }
        delete[] filmLista;
    }
};


#endif //SKELETON_FILMTAR_H
