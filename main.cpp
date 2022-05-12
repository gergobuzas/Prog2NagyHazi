#include <iostream>
#include "film.h"
#include "filmtar.h"
#include "menu.hpp"
#include "gtest_lite.h"
#include "string5.h"
using std::cout;
using std::cin;
using std::endl;


int main() {
    FilmTar filmtomb;
    filmtomb.adatbazisBeolvas("Csaladifilm.txt");
    filmtomb.adatbazisBeolvas("Dokumentumfilm.txt");
    menu(filmtomb);
    return 0;
}
