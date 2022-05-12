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

    unsigned int getMeret() const{ return meret;}


    Film** getFilmLista() {return filmLista;}

    void adatbazisBeolvas(const char *fajlNev);

    void adatbazisHozzaad(Film* ujFilm);

    void adatbazisTorol(String& torlendoFilm);

    void adatbazisMentes(const char *fajlNev);

    void osszesKiir();

    ~FilmTar(){
        for (unsigned int i = 0; i < meret; ++i) {
            delete(filmLista[i]);
        }
        delete[] filmLista;
    }
};


#endif //SKELETON_FILMTAR_H
