/**
 * @file film.h
 * @author Gergo Buzas (buzasgergo0615@gmail.com)
 * @brief A header for the different categories of films, that can be stored in the database
 * @version 0.1
 * @date 2022-05-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef SKELETON_FILM_H
#define SKELETON_FILM_H

#include <iostream>
#include "string5.h"

/**
 * @brief The parent class of the different categories of Films.
 * 
 */
class Film{
private:
    unsigned int id;
    String cim;
    unsigned int lejatszIdo;
    unsigned int kiadEv;
    String kategoria;
public:
    /**
     * @brief The constructor of the class
     * 
     */
    Film(unsigned int cid, String ccim, unsigned int clejatszIdo, unsigned int ckiadEv,\
    String ckategoria): id(cid), cim(ccim), lejatszIdo(clejatszIdo), kiadEv(ckiadEv), kategoria(ckategoria){}

    /**
     * @brief Get the Id object
     * 
     * @return unsigned int 
     */
    unsigned int getId() const{ return id; }

    /**
     * @brief Get the Cim object
     * 
     * @return String 
     */
    String getCim() const { return cim; }


    /**
     * @brief Get the Lejatsz Ido object
     * 
     * @return unsigned int 
     */
    unsigned int getLejatszIdo() const { return lejatszIdo;}

    /**
     * @brief Get the kiad Ev object
     * 
     * @return unsigned int 
     */
    unsigned int getkiadEv() const { return kiadEv; }

    /**
     * @brief Get the Kategoria object
     * 
     * @return String 
     */
    String getKategoria() const { return kategoria; }


    /**
     * @brief An output function. The datas are nicely styled. Comes in handy for printing to the standard output
     * 
     * @param out Where the data is written to
     * @return std::ostream& 
     */
    virtual std::ostream& formazottKiir(std::ostream& out) const;

    /**
     * @brief An output function. Non-styled. Used for the writing of the database
     * 
     * @param out Where the data is written to
     * @return std::ostream& 
     */
    virtual std::ostream& kiir(std::ostream& out) const;
};

/**
 * @brief A derived class of Film. Adds a description(leiras) to the list of storable data in Film.
 * 
 */
class DokumentumFilm: public Film{
private:
    String leiras;
public:
    /**
     * @brief The constructor of the class
     * 
     */
    DokumentumFilm(unsigned int cid, String ccim, unsigned int clejatszIdo, unsigned int ckiadEv,\
    String ckategoria, String cleiras) : Film(cid, ccim, clejatszIdo, ckiadEv, ckategoria), leiras(cleiras){}

    /**
     * @brief An output function. The datas are nicely styled. Comes in handy for printing to the standard output
     * 
     * @param out Where the data is written to
     * @return std::ostream& 
     */
    std::ostream& formazottKiir(std::ostream& out) const override;

    /**
     * @brief An output function. Non-styled. Used for the writing of the database
     * 
     * @param out Where the data is written to
     * @return std::ostream& 
     */
    std::ostream& kiir(std::ostream& out) const;
};

/**
 * @brief A derived class of Film. Adds a minimum age limit (korhatar) to the list of storable data in Film.
 * 
 */
class CsaladiFilm: public Film{
private:
    unsigned int korhatar;
public:
    /**
     * @brief The constructor of the class
     * 
     */
    CsaladiFilm(unsigned int cid, String ccim, unsigned int clejatszIdo, unsigned int ckiadEv,\
    String ckategoria, unsigned int ckorhatar) : Film(cid, ccim, clejatszIdo, ckiadEv, ckategoria), korhatar(ckorhatar){}

    /**
     * @brief An output function. The datas are nicely styled. Comes in handy for printing to the standard output
     * 
     * @param out Where the data is written to
     * @return std::ostream& 
     */
    std::ostream& formazottKiir(std::ostream& out) const override;

    /**
     * @brief An output function. Non-styled. Used for the writing of the database 
     * 
     * @param out Where the data is written to
     * @return std::ostream& 
     */
    std::ostream& kiir(std::ostream& out) const;

};

#endif //SKELETON_FILM_H
