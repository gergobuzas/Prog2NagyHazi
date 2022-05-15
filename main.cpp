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

    TEST(konstruktorok_tesztelese, konstruktor_teszt) {
            DokumentumFilm dokfilm(1, "Teszt", 10, 2010, "Dokumentumfilm", "Teszt film.");
            EXPECT_EQ(1, dokfilm.getId()) << "A fuggveny hibas id-t adott" << std::endl;
            EXPECT_EQ(10, dokfilm.getLejatszIdo()) << "A fuggveny hibas lejatszasi idot adott" << std::endl;
            EXPECT_EQ(2010, dokfilm.getkiadEv()) << "A fuggveny hibas kiadasi evet adott" << std::endl;
            EXPECT_STREQ("Dokumentumfilm", dokfilm.getKategoria().c_str()) << "A fuggveny hibas adatot adott vissza" << std::endl;
            EXPECT_STREQ("Teszt film.", dokfilm.getLeiras().c_str()) << "A fuggveny hibas adatot adott vissza" << std::endl;
            EXPECT_STREQ("Teszt", dokfilm.getCim().c_str()) << "A fuggveny hibas adatot adott vissza" << std::endl;

            CsaladiFilm csalfilm(2, "Teszt2", 20, 2011, "Csaladifilm", 3);
            EXPECT_EQ(2, csalfilm.getId()) << "A fuggveny hibas id-t adott" << std::endl;
            EXPECT_EQ(20, csalfilm.getLejatszIdo()) << "A fuggveny hibas lejatszasi idot adott" << std::endl;
            EXPECT_EQ(2011, csalfilm.getkiadEv()) << "A fuggveny hibas kiadasi evet adott" << std::endl;
            EXPECT_EQ(3, csalfilm.getKorhatar()) << "A fuggveny hibas kor-t adott" << std::endl;
            EXPECT_STREQ("Csaladifilm", csalfilm.getKategoria().c_str()) << "A fuggveny hibas adatot adott vissza" << std::endl;
            EXPECT_STREQ("Teszt2", csalfilm.getCim().c_str()) << "A fuggveny hibas adatot adott vissza" << std::endl;
    }END

    TEST(beolvasas_tesztelese, elsoElem_adatai) {
            FilmTar filmtomb;
            filmtomb.adatbazisBeolvas("CsaladiFilm.txt");
            filmtomb.adatbazisBeolvas("DokumentumFilm.txt");
            EXPECT_EQ(4, filmtomb.getMeret()) << "A fuggveny hibas meretet adott" << std::endl;
            EXPECT_STREQ("Az oroszlankiraly", filmtomb.getFilmLista()[0]->getCim().c_str()) << "A fuggveny hibasan olvasott be adatot" << std::endl;
            EXPECT_EQ(88, filmtomb.getFilmLista()[0]->getLejatszIdo()) << "A fuggveny hibasan olvasott be lejatszasi idot" << std::endl;
            EXPECT_EQ(1994, filmtomb.getFilmLista()[0]->getkiadEv()) << "A fuggveny hibasan olvasott be kiadasi evet" << std::endl;
            EXPECT_STREQ("Csaladifilm", filmtomb.getFilmLista()[0]->getKategoria().c_str()) << "A függveny hibasan olvasott be kategoriat" << std::endl;
            filmtomb.adatbazisMentes("DokumentumFilm.txt");
            filmtomb.adatbazisMentes("CsaladiFilm.txt");
        }END

    TEST(hozzaadas_tesztelese, masodikElem_adatai) {
            FilmTar filmtomb2;
            filmtomb2.adatbazisBeolvas("CsaladiFilm.txt");
            filmtomb2.adatbazisBeolvas("DokumentumFilm.txt");
            DokumentumFilm* hozzaadando2 = new DokumentumFilm(filmtomb2.getMeret() + 1, "Hozzaadott", 25, 2022, "Dokumentumfilm", "Ez egy jo film");
            filmtomb2.adatbazisHozzaad(hozzaadando2);
            EXPECT_EQ(5, filmtomb2.getMeret()) << "A fuggveny hibas meretet adott" << std::endl;
            EXPECT_STREQ("Hozzaadott", filmtomb2.getFilmLista()[4]->getCim().c_str())  << "A fuggveny hibasan olvasott be adatot" << std::endl;
            EXPECT_EQ(25, filmtomb2.getFilmLista()[4]->getLejatszIdo()) << "A fuggveny hibasan olvasott be lejatszasi idot" << std::endl;
            EXPECT_EQ(2022, filmtomb2.getFilmLista()[4]->getkiadEv()) << "A fuggveny hibasan olvasott be kiadasi evet" << std::endl;
            EXPECT_STREQ("Dokumentumfilm", filmtomb2.getFilmLista()[4]->getKategoria().c_str()) << "A fuggveny hibasan olvasott be kategoriat" << std::endl;
            filmtomb2.adatbazisMentes("CsaladiFilm.txt");
            filmtomb2.adatbazisMentes("DokumentumFilm.txt");
        }END

    TEST(torles_tesztelese, elsoElem_adatai) {
            FilmTar filmtomb3;
            filmtomb3.adatbazisBeolvas("CsaladiFilm.txt");
            filmtomb3.adatbazisBeolvas("DokumentumFilm.txt");
            String torlendo3 = "Hozzaadott";
            filmtomb3.adatbazisTorol(torlendo3);
            EXPECT_EQ(4, filmtomb3.getMeret()) << "A fuggveny hibas meretet adott" << std::endl;
            EXPECT_STREQ("Az oroszlankiraly", filmtomb3.getFilmLista()[0]->getCim().c_str()) << "A fuggveny hibasan olvasott be adatot" << std::endl;
            EXPECT_EQ(88, filmtomb3.getFilmLista()[0]->getLejatszIdo()) << "A fuggveny hibasan olvasott be lejatszasi idot" << std::endl;
            EXPECT_EQ(1994, filmtomb3.getFilmLista()[0]->getkiadEv()) << "A fuggveny hibasan olvasott be kiadasi evet" << std::endl;
            EXPECT_STREQ("Csaladifilm", filmtomb3.getFilmLista()[0]->getKategoria().c_str()) << "A fuggveny hibasan olvasott be kategoriat" << std::endl;
            filmtomb3.adatbazisMentes("CsaladiFilm.txt");
            filmtomb3.adatbazisMentes("DokumentumFilm.txt");
        }END


        /**
         * String mukodes
         */

        TEST(Elkeszult1, construct) {
          String ures;
          ures.printDbg("Ures sztring: ");   // debug kiíratás
          if (ures.size() != 0)
            FAIL() << "Baj van a string hosszaval" << endl;
    #ifndef CPORTA
          else
            SUCCEED() << "Hurra! Van egy sztringem, de nem biztos, hogy ures!" << endl;
    #endif // CPORTA
        } ENDM


        TEST(Elkeszult2, emptyStr) {
          String ures;
          EXPECT_EQ((size_t)0, ures.size()) << "Baj van a string hosszaval" << endl;

          /// Ellenőrizzük, hogy üres sztringet ("") kaptunk-e vissza?
          EXPECT_STREQ("", ures.c_str()) << "Nem ures sztring jott letre" << endl;
        } ENDM


        TEST(Elkeszult3, fromChr) {
          char ch = 'a';
          String a(ch);
          EXPECT_EQ((size_t)1, a.size()) << "Baj van a string hosszaval" << endl;
          EXPECT_STREQ("a", a.c_str()) << "Karakterbol sztring letrehozasa nem sikerult!" << endl;

          String b('a');    // konstansból is megy?
          EXPECT_STREQ("a", b.c_str()) << "Karakterbol sztring letrehozasa nem sikerult!" << endl;
        } ENDM



        TEST(Elkeszult4, FromCstr) {
          const char *hello = "Hello sztring";
          String a(hello);
          EXPECT_EQ(strlen(hello), a.size()) << "Baj van a string hosszaval" << endl;
          EXPECT_STREQ(hello, a.c_str()) << "C-sztringbol string letrehozasa nem sikerult!" << endl;

          /// Ellenőrizzük, hogy lemásolta-e a sztringet. Nem elég a pointert!
          char cpp[] = { 'C', '+', '+', '\0' };
          String b(cpp);
          cpp[0] = 'X';
          EXPECT_STRNE(cpp, b.c_str()) << "FromCstr: le kellett volna masolni a karaktertombot!" << endl;
        } ENDM


        TEST(Elkeszult5, ctor) {
          const char *hello = "Hello sztring";
          String a(hello);
          String b = a;
          EXPECT_EQ(strlen(hello), b.size()) << "Baj van a string hosszaval!" << endl;
          EXPECT_STREQ(hello, b.c_str()) << "Baj van a masolo konstruktorral!" << endl;

          /// Ellenőrizzük, hogy lemásolta-e a sztringet. Nem elég a pointert!
          if (a.c_str() == b.c_str())     // Ha a két pointer egyezik, akkor nem másolta le az adatot
             FAIL()  << "!** ctor: nem elegendo a pointereket lemasolni!" << endl;

          EXPECT_STREQ(hello, a.c_str()) << "Masolo kontsr. elromlott a forras!" << endl;
          EXPECT_EQ(strlen(hello), a.size()) << "Masolo konstr. alatt elromlott a forras hossza!" << endl;

          const String c = a;
          String d = c;     // konstansból is megy?
          EXPECT_STREQ(hello, d.c_str()) << "Baj van a masolo konstruktorral" << endl;
        } ENDM

        TEST(Elkeszult5, ctor_nullptr) {
          String d0;
          String ures = d0;     // üres sztringet is le tudja másolni?
          EXPECT_EQ((size_t)0, ures.size()) << "Baj van a string hosszaval" << endl;
          /// Ellenőrizzük, hogy üres sztringet ("") kaptunk-e vissza?
          EXPECT_STREQ("", ures.c_str()) << "Nem ures sztring jott letre" << endl;
        } ENDM

        TEST(Elkeszult6, opAssign) {
          const char *hello = "Hello sztring";
          String a(hello);
          String b("Duma1"), c("Duma2");
          EXPECT_STRNE(a.c_str(), b.c_str());
          a = a;
          EXPECT_EQ(strlen(hello), a.size()) << "Baj van az ertekadassal: a = a hossz" << endl;
          EXPECT_STREQ(hello, a.c_str()) << "Baj van az ertekadassal: a = a" << endl;
          c = b = a;

          /// Ellenőrizzük, hogy lemásolta-e a sztringet. Nem elég a pointert!
          if (a.c_str() == b.c_str())     // Ha a két pointer egyezik, akkor nem másolta le az adatot
             FAIL()  << "!** op=: nem elegendo a pointereket lemasolni!" << endl;

          EXPECT_EQ(strlen(hello), a.size()) << "Ertekedasnal elromlott a forras hossza!" << endl;
          EXPECT_STREQ(hello, a.c_str()) << "Ertekadasnal elromlott a forras!" << endl;
          EXPECT_EQ(strlen(hello), b.size()) << "Ertekedas: nem jo a hossz!" << endl;
          EXPECT_STREQ(hello, b.c_str()) << "Ertekadas nem sikerult!" << endl;
          EXPECT_EQ(strlen(hello), c.size()) << "Ertekedas: nem jo a hossz!" << endl;
          EXPECT_STREQ(hello, c.c_str()) << "Ertekadas nem sikerult!" << endl;

          const String d("Konst.");
          c = d;        // konstansból is megy?
          EXPECT_EQ(c.size(), c.size()) << "Ertekedas konstansbol: nem jo a hossz!" << endl;
          EXPECT_STREQ(d.c_str(), c.c_str()) << "Ertekadas konstansbol nem sikerult!" << endl;
        } ENDM

        TEST(Elkeszult6, opAssign_nullptr) {
          String d0;
          String c = d0;     // üres sztringet is le tudja másolni?
          EXPECT_EQ((size_t)0, c.size()) << "Baj van a string hosszaval" << endl;
          /// Ellenőrizzük, hogy üres sztringet ("") kaptunk-e vissza?
          EXPECT_STREQ("", c.c_str()) << "Nem ures sztring jott letre" << endl;

        } ENDM

        TEST(Elkeszult7, strPlusStr) {
          String a("Hello ");
          String b("sztring");
          String c;
          c = a + b;
          EXPECT_STREQ("Hello sztring", c.c_str()) << "Nem sikerult a + String muvelet!" << endl;
          EXPECT_STREQ("Hello ", a.c_str()) << "A + muvelet elrontja a bal oldalt?" << endl;
          EXPECT_STREQ("sztring", b.c_str()) << "A + muvelet elrontja a jobb oldalt?" << endl;
          const String a1 = a, b1 = b;

          String c1;
          c1 = a1 + b1;          // konstansból is megy?
          EXPECT_STREQ("Hello sztring", c1.c_str()) << "Nem sikerult a + String muvelet!" << endl;
        } ENDM

        TEST(Elkeszult7, strPlusChr) {
          String a("Hello ");
          String b;
          b = a + 'B';
          EXPECT_STREQ("Hello B", b.c_str()) << "Nem sikerult a + char muvelet!" << endl;
          EXPECT_STREQ("Hello ", a.c_str()) << "A + muvelet elrontja a bal oldalt?" << endl;

          const String a1 = a;
          String b1;
          b1 = a1 + 'B';          // konstansból is megy?
          EXPECT_STREQ("Hello B", b1.c_str()) << "Nem sikerult a + char muvelet!" << endl;
          EXPECT_STREQ("Hello ", a1.c_str()) << "A + muvelet elrontja a bal oldalt?" << endl;

        } ENDM
        TEST(Elkeszult8, chrPlusStr) {
          String a("ello");
          String b;
          char h = 'H';
          b = h + a;
          EXPECT_STREQ("Hello", b.c_str()) << "Nem sikerult char + Str muvelet!" << endl;
          EXPECT_STREQ("ello", a.c_str()) << "A + muvelet elrontja a jobb oldalt?" << endl;

          String b1;
          b1 = 'H' + a;  // konstanssal is megy?
          EXPECT_STREQ("Hello", b.c_str()) << "Nem sikerult char + Str muvelet!" << endl;
        } ENDM

        TEST(Elkeszult9, index) {
          String a("Hello 678");
          EXPECT_NO_THROW(a[0]);
          EXPECT_NO_THROW(a[7]);
          EXPECT_NO_THROW(a[8]);
          EXPECT_THROW(a[9], const char *);
          EXPECT_THROW(a[-1], const char *);
          EXPECT_EQ('7', a[7]);
          a[7] = '.';
          EXPECT_EQ('.', a[7]);
        } ENDM

        TEST(Elkeszult10, insert) {
          String a("Hello sztring");
          std::stringstream ss;
          ss << a;
          EXPECT_STREQ("Hello sztring", ss.str().c_str());
        } ENDM


    cout << "\n\nSikeresen lefutott minden teszteset!" << endl;
    return 0;
}

int main(int argc, char** argv) {
#if defined(CPORTA)
    testMain();
#else
    releaseMain(argc, argv);
#endif
}

