/**
 * @file filmtar.h
 * @author Gergo Buzas (buzasgergo0615@gmail.com)
 * @brief The FilmTar class is the one implementing the heterogenous collection of the different categories of films. It is also managing the data of the database.
 * @version 0.1
 * @date 2022-05-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "film.h"
#include "string5.h"


#ifndef SKELETON_FILMTAR_H
#define SKELETON_FILMTAR_H

/**
 * @brief The class that implements the heterogenous collection 
 * 
 */
class FilmTar{
private:
    unsigned int meret = 0;
    Film** filmLista = nullptr;
public:
    /**
     * @brief Construct a new Film Tar object
     * 
     */
    FilmTar() = default;

    /**
     * @brief Get the Meret object
     * 
     * @return unsigned int 
     */
    unsigned int getMeret() const{ return meret;}

    /**
     * @brief Get the Film Lista object
     * 
     * @return Film** 
     */
    Film** getFilmLista() {return filmLista;}
    
    /**
     * @brief Reads the data from the database txt into a heterogenous collection 
     * 
     * @param fajlNev The name of the database file
     */
    void adatbazisBeolvas(const char *fajlNev);

    /**
     * @brief Adds a new Film to the heterogenous collection (filmLista). Reallocates the memory every time you add an object. 
     * 
     * @param ujFilm The Film object that you want to add to the heterogenous collection
     */
    void adatbazisHozzaad(Film* ujFilm);

    /**
     * @brief Allows the user to input data of a film, and add it to the heterogenous collection (filmLista). If the film that the user wants to add is already in the database, than the function is returned.
     * 
     * @param valtozasVolt To help us determine, whether we have to write to the database txt upon closing the program to save the changes (only happens when there were changes made, which is determined based on this bool)
     */
    void adatbazisHozzaadFelhasznalo(bool& valtozasVolt);

    /**
     * @brief Removes a Film from the heterogenous collection (filmLista). Reallocates the memory every time you remove an object.
     * 
     * @param torlendoFilm 
     */
    void adatbazisTorol(String& torlendoFilm);

    /**
     * @brief Asks user about which film to delete
     * 
     * @param valtozasVolt To help us determine, whether we have to write to the database txt upon closing the program to save the changes (only happens when there were changes made, which is determined based on this bool)
     */
    void adatbazisTorolFelhasznalo(bool& valtozasVolt);

    /**
     * @brief Writes the data of the films into the database txt files
     * 
     * @param fajlNev The output database file (txt)
     */
    void adatbazisMentes(const char *fajlNev);

    /**
     * @brief Calls the formazottKiir() function for every single film, that is stored in the heterogenous collection (filmLista). It is nicely styled, and is mostly useful for writing to the standard output.
     * 
     */
    void osszesformazottKiir();

    /**
     * @brief Destroy the Film Tar object
     * 
     */
    ~FilmTar(){
        for (unsigned int i = 0; i < meret; ++i) {
            delete(filmLista[i]);
        }
        delete[] filmLista;
    }
};


#endif //SKELETON_FILMTAR_H
