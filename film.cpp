//
// Created by buzas on 2022. 05. 12..
//
#include <iostream>
#include "film.h"

std::ostream& Film::kiir(std::ostream& out = std::cout) const{
    out << id << std::endl;
    out << cim << std::endl;
    out << lejatszIdo << std::endl;
    out << kategoria << std::endl;
    return out;
}

std::ostream& DokumentumFilm::kiir(std::ostream& out = std::cout) const{
    out << getId() << std::endl;
    out << getCim() << std::endl;
    out << getLejatszIdo() << std::endl;
    out << getKategoria() << std::endl;
    out << leiras << std::endl;
    return out;
}

std::ostream& CsaladiFilm::kiir(std::ostream& out = std::cout) const{
    out << getId() << std::endl;
    out << getCim() << std::endl;
    out << getLejatszIdo() << std::endl;
    out << getKategoria() << std::endl;
    out << korhatar << std::endl;
    return out;
}
