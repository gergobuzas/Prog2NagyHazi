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

int main() {
    FilmTar filmtomb;
    filmtomb.adatbazisBeolvas("CsaladiFilm.txt");
    filmtomb.adatbazisBeolvas("DokumentumFilm.txt");
    menu(filmtomb);
    return 0;
}
