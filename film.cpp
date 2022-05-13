//
// Created by buzas on 2022. 05. 12..
//
#include <iostream>
#include "film.h"
#include "memtrace.h"

using std::cout;
using std::endl;

std::ostream& Film::kiir(std::ostream& out = std::cout) const{
    out << id << std::endl;
    out << cim << std::endl;
    out << lejatszIdo << std::endl;
    out << kiadEv << std::endl;
    out << kategoria << std::endl;
    out << '\n';
    return out;
}

std::ostream& DokumentumFilm::kiir(std::ostream& out = std::cout) const{
    out << getId() << std::endl;
    out << getCim() << std::endl;
    out << getLejatszIdo() << std::endl;
    out << getkiadEv() << std::endl;
    out << getKategoria() << std::endl;
    out << leiras << std::endl;
    out << '\n';
    return out;
}

std::ostream& CsaladiFilm::kiir(std::ostream& out = std::cout) const{
    out << getId() << std::endl;
    out << getCim() << std::endl;
    out << getLejatszIdo() << std::endl;
    out << getkiadEv() << std::endl;
    out << getKategoria() << std::endl;
    out << korhatar << std::endl;
    out << '\n';
    return out;
}

std::ostream& Film::formazottKiir(std::ostream& out) const{
    cout << "id: " << id << endl;
    cout << "Cim: " << cim << endl;
    cout << "Lejatszasi ido: " << lejatszIdo << endl;
    cout << "Kiadasi ev: " << kiadEv << endl;
    return cout;
}

std::ostream& DokumentumFilm::formazottKiir(std::ostream& out) const{
    cout << "id: " << getId() << endl;
    cout << "Cim: " << getCim() << endl;
    cout << "Lejatszasi ido: " << getLejatszIdo() << endl;
    cout << "Kiadasi ev: " << getkiadEv() << endl;
    cout << "Kategoria: Dokumentumfilm" << endl;
    cout << "Leiras: " << leiras << endl;
    return cout;
}

std::ostream& CsaladiFilm::formazottKiir(std::ostream& out) const{
    cout << "id: " << getId() << endl;
    cout << "Cim: " << getCim() << endl;
    cout << "Lejatszasi ido: " << getLejatszIdo() << endl;
    cout << "Kiadasi ev: " << getkiadEv() << endl;
    cout << "Kategoria: Csaladifilm" << endl;
    cout << "Korhatar: " << korhatar << endl;
    return cout;
}
