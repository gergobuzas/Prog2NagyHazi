//
// Created by buzas on 2022. 04. 24..
//


#ifndef SKELETON_FILM_H
#define SKELETON_FILM_H

#include <iostream>
#include "string5.h"


class Film{
private:
    unsigned int id;
    String cim;
    unsigned int lejatszIdo;
    unsigned int kiadEv;
    String kategoria;
public:
    Film(unsigned int cid, String ccim, unsigned int clejatszIdo, unsigned int ckiadEv,\
    String ckategoria): id(cid), cim(ccim), lejatszIdo(clejatszIdo), kiadEv(ckiadEv), kategoria(ckategoria){}

    unsigned int getId() const;

    String getCim() const;

    unsigned int getLejatszIdo() const;

    unsigned int getkiadEv();

    String getKategoria() const;

    virtual void kiir() = 0;

    virtual ~Film();

};


class DokumentumFilm: public Film{
private:
    String leiras;
public:
    DokumentumFilm(unsigned int cid, String ccim, unsigned int clejatszIdo, unsigned int ckiadEv,\
    String ckategoria, String cleiras) : Film(cid, ccim, clejatszIdo, ckiadEv, ckategoria), leiras(cleiras){}

    String getLeiras() const;

    void kiir();

    ~DokumentumFilm();
};

class CsaladiFilm: public Film{
private:
    unsigned int korhatar;
public:
    CsaladiFilm(unsigned int cid, String ccim, unsigned int clejatszIdo, unsigned int ckiadEv,\
    String ckategoria, unsigned int ckorhatar) : Film(cid, ccim, clejatszIdo, ckiadEv, ckategoria), korhatar(ckorhatar){}

    String getLeiras() const;

    void kiir();

    ~CsaladiFilm();
};

#endif //SKELETON_FILM_H
