#include <iostream>
#include "film.h"
#include "filmtar.h"
#include "gtest_lite.h"
#include "string5.h"
using std::cout;
using std::cin;
using std::endl;


int main() {
    FilmTar filmtomb;
    TEST(beolvasas_tesztelese, elsoElem_adatai) {
            filmtomb.adatbazisBeolvas("test.txt");
            EXPECT_EQ(1, filmtomb.getMeret()) << "A függvény hibás méretet adott" << std::endl;
            EXPECT_STREQ("testfilm", filmtomb.getFilmLista()[0]->getCim().c_str()) << "A függvény hibásan olvasott be adatot" << std::endl;
            EXPECT_EQ(100, filmtomb.getFilmLista()[0]->getLejatszIdo()) << "A függvény hibásan olvasott be lejátszási időt" << std::endl;
            EXPECT_EQ(2015, filmtomb.getFilmLista()[0]->getkiadEv()) << "A függvény hibásan olvasott be kiadási évet" << std::endl;
            EXPECT_STREQ("Dokumentumfilm", filmtomb.getFilmLista()[0]->getKategoria().c_str()) << "A függvény hibásan olvasott be kategóriát" << std::endl;
        }END
    cout << "Első teszt sikeres!" << endl;

    TEST(hozzaadas_tesztelese, masodikElem_adatai) {
            DokumentumFilm hozzaadando(filmtomb.getMeret(), "Hozzaadott", 25, 2022, "Dokumentumfilm", "Ez egy jo film");
            filmtomb.adatbazisHozzaad(&hozzaadando);
            EXPECT_EQ(2, filmtomb.getMeret()) << "A függvény hibás méretet adott" << std::endl;
            EXPECT_STREQ("Hozzaadott", filmtomb.getFilmLista()[1]->getCim().c_str())  << "A függvény hibásan olvasott be adatot" << std::endl;
            EXPECT_EQ(25, filmtomb.getFilmLista()[0]->getLejatszIdo()) << "A függvény hibásan olvasott be lejátszási időt" << std::endl;
            EXPECT_EQ(2022, filmtomb.getFilmLista()[0]->getkiadEv()) << "A függvény hibásan olvasott be kiadási évet" << std::endl;
            EXPECT_STREQ("Dokumentumfilm", filmtomb.getFilmLista()[0]->getKategoria().c_str()) << "A függvény hibásan olvasott be kategóriát" << std::endl;
        }END
    cout << "Második teszt sikeres!" << endl;

    TEST(torles_tesztelese, elsoElem_adatai) {
            filmtomb.adatbazisTorol("Hozzaadott");
            filmtomb.getFilmLista()[0]->kiir();
            EXPECT_EQ(1, filmtomb.getMeret()) << "A függvény hibás méretet adott" << std::endl;
            EXPECT_STREQ("testfilm", filmtomb.getFilmLista()[0]->getCim().c_str()) << "A függvény hibásan olvasott be adatot" << std::endl;
            EXPECT_EQ(100, filmtomb.getFilmLista()[0]->getLejatszIdo()) << "A függvény hibásan olvasott be lejátszási időt" << std::endl;
            EXPECT_EQ(2015, filmtomb.getFilmLista()[0]->getkiadEv()) << "A függvény hibásan olvasott be kiadási évet" << std::endl;
            EXPECT_STREQ("Dokumentumfilm", filmtomb.getFilmLista()[0]->getKategoria().c_str()) << "A függvény hibásan olvasott be kategóriát" << std::endl;
        }END
    cout << "Harmadik teszt sikeres!" << endl;

    TEST(mentes_tesztelese, mentesFajlba_majdBeolvasas) {
            filmtomb.adatbazisMentes("test2.txt");
            FilmTar filmtomb2;
            filmtomb2.adatbazisBeolvas("test2.txt");
            EXPECT_EQ(1, filmtomb2.getMeret()) << "A függvény hibás méretet adott" << std::endl;
            EXPECT_STREQ("testfilm", filmtomb2.getFilmLista()[0]->getCim().c_str()) << "A függvény hibásan olvasott be adatot" << std::endl;
            EXPECT_EQ(100, filmtomb.getFilmLista()[0]->getLejatszIdo()) << "A függvény hibásan olvasott be lejátszási időt" << std::endl;
            EXPECT_EQ(2015, filmtomb.getFilmLista()[0]->getkiadEv()) << "A függvény hibásan olvasott be kiadási évet" << std::endl;
            EXPECT_STREQ("Dokumentumfilm", filmtomb.getFilmLista()[0]->getKategoria().c_str()) << "A függvény hibásan olvasott be kategóriát" << std::endl;
        }END
    cout << "Negyedik teszt sikeres!" << endl;

    cout << "\n\nSikeresen lefutott minden teszteset!" << endl;
    SUCCEED();
    return 0;
}
