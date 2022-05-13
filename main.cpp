#include <iostream>
#include "film.h"
#include "filmtar.h"
#include "menu.hpp"
#include "gtest_lite.h"
#include "string5.h"
#include "memtrace.h"

using std::cout;
using std::cin;
using std::endl;

//teszteléshez vedd ki a kommentet
//#define CPORTA

int releaseMain(int argc, char** argv) {
    FilmTar filmtomb;
    filmtomb.adatbazisBeolvas("CsaladiFilm.txt");
    filmtomb.adatbazisBeolvas("DokumentumFilm.txt");
    menu(filmtomb);
    return 0;
}

int testMain() {

    return 0;
}

int main(int argc, char** argv) {
#if defined(CPORTA)
    testMain();
#else
    releaseMain(argc, argv);
#endif
    return 0;
}

