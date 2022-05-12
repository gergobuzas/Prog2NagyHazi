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

    unsigned int getId() const{ return id; }

    String getCim() const { return cim; }

    unsigned int getLejatszIdo() const { return lejatszIdo;}

    unsigned int getkiadEv() const { return kiadEv; }

    String getKategoria() const { return kategoria; }

    virtual std::ostream& kiir(std::ostream& out) const;

    //virtual ~Film();

};


class DokumentumFilm: public Film{
private:
    String leiras;
public:
    DokumentumFilm(unsigned int cid, String ccim, unsigned int clejatszIdo, unsigned int ckiadEv,\
    String ckategoria, String cleiras) : Film(cid, ccim, clejatszIdo, ckiadEv, ckategoria), leiras(cleiras){}

    String getLeiras() const { return leiras;}

    std::ostream& kiir(std::ostream& out) const;

    //~DokumentumFilm();
};

class CsaladiFilm: public Film{
private:
    unsigned int korhatar;
public:
    CsaladiFilm(unsigned int cid, String ccim, unsigned int clejatszIdo, unsigned int ckiadEv,\
    String ckategoria, unsigned int ckorhatar) : Film(cid, ccim, clejatszIdo, ckiadEv, ckategoria), korhatar(ckorhatar){}

    String getKorhatar() const { return korhatar; }

    std::ostream& kiir(std::ostream& out) const;

    //~CsaladiFilm();
};

#endif //SKELETON_FILM_H
