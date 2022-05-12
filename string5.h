#ifndef STRING_H
#define STRING_H
/**
 * \file string2_kesz.h
 *
 * Ez a fájl tartalmazza a
 *   - String osztály deklarációját
 *   - az inline függvényeket. Ha valamit inline-ként akar megvalósítani,
 *     akkor azt ebbe a fájlba írja! Tipikusan a rövid kódokat szokás
 *     inline-két megvalósítani (pl: c_str).
 *     Más függvényeket ill. definíciókat ne írjon a .h fájlba!
 *
 * A C-ben megírt (string1.c) függvények most tagfüggvényekké váltak, és
 *   eltűnt az első paraméterük (s0) (ebből lett a this).
 * A nevük is megváltozott, mert most már az összetartozást, és a
 *   paraméterek típusára való utalást már nem a név hordozza, hanem az osztály.
 * A createString... alakú függvényekből konstruktorok keletkeztek.
 * A disposeString destruktorrá alakült át.
 * Egyes műveletvégző függvényekből pedig operátor függvény lett.
 */

/**
 * Az Ön feladata a string2.cpp fájlban megvalósítani (definiálni) az egyes
 * függvényeket.
 *
 * Ahogyan halad a megvalósítással egyre több tesztesetet kell lefuttatni,
 * ezért az ELKESZULT makró értéket folyamatosan növelje a feladatsorszámoknak
 * megfelelően!
 *
 * Tanulságos a megvalósítás előtt már a megnövelt értékkel is lefordítani
 * a programot, és elemezni a kapott hibajelzést.
 *
 */

#define ELKESZULT 13

/**
 * \section fel Feladat:
 * A tantermi gyakorlatokon, valamint a 3. laborgyakorlaton is foglalkoztunk egy
 * olyan sztring (String) adatszerkezet és a rajta műveleteket végző függvények
 * megtervezésével/impelmentálásával ami dinamikusan tárol és annyi memóriát foglal
 * amennyi a tároláshoz szükséges.
 *
 * Ezeket és a tanultakat felhasználva a string2.h és a string2.cpp állományokban
 * definiáljon ill. implementáljon egy olyan sztring (String) osztályt C++ nyelven, ami
 * dinamikusan tárol és rendelkezik az alábbi tulajosnágokkal!
 *
 *  1  A paraméter nélkül hívható konstruktora üres sztringet hozzon étre!
 *  2. Van olyan tagfüggvénye ( c_str() ), ami C-sztringgel, azaz nullával lezárt
 *     karaktersorozatra mutató pointerel (const char *) tér vissza.
 *  3. Van olyan konstruktora, ami karakterből hoz létre sztringet.
 *  4. Van olyan konstruktora, ami C-sztringből (const char*) hoz létre sztringet.
 *  5. Az osztályból létrehozott objektum legyen átadható értékkparaméterként!
 *  6. Támogassa a többszörös értékadást (b = a = a)!
 *  7  Legyenek olyan operárorai (operator+), amivel a sztring végéhez sztringet,
 *     és karaktert lehet fűzni!
 *  8. Lehessen karakterhez is sztringet fűzni a + operátorral!
 *  9. A tárolt a karakterek legyenek elérhetőek a szokásos módon indexeléssel!
 *     Az indexeléssel elér elem legyen használható balértékként is!
 *     A konstans objektumok is legyenek indexelhetők.
 *     Az indexelés operátor hiba esetén dobjon const char * kivételt!
 * 10. Készítsen olyan << operátort, amivel egy sztring kiírható egy ostream típusú
 *     objektumra!
 *
 * Szorgalmi feladatok:
 * 11. Készítsen olyan fűzhető >> operátort, amivel be tud olvasni egy szót egy sztring-be!
 *     A beolvasó működjön úgy, mint a scanf %s, azaz a szó végét white space határolja!
 *     A szó eleji white space karaktereket pedig el kell dobni.
 *    *Megj: az istream wshite space kezelése a flags() tagfüggvénnyel szabályozható
 * 12. Próbálja ki az ékezetes karakterek rendezését is! Ehhez elkészítettünk egy
 *     egyszerű kódrészletet ami qsort() függvényt használ.
 *     Értse meg a rendez.cpp fájlban levő kód működését és futtassa a programot!
 * 13. A setlocale függvényhívás beállítja a karakterek és sztringek összehasonlításához
 *     szükséges nyelvi környezetet (LC_COLLATE) próbálja ki! Változott a rendezési
 *     sorrend?
 */

#include <iostream>
/**
 * Header fájlokból megfontoltan kell include-ot használni.
 * Névteret azonban nem célszerű kinyitni, mert annak hatása zavaró lehet
 * ott ahol ez a header include-olva lesz.
 */

#ifndef MEMTRACE

#endif // MEMTRACE

/**
 * A String osztály.
 * A 'pData'-ban vannak a karakterek (a lezáró nullával együtt), 'len' a hossza.
 * A hosszba nem számít bele a lezáró nulla.
 */
class String {
    char *pData;         /// pointer az adatra
    size_t len;    /// hossz lezáró nulla nélkül
public:
/// Az első két feladatot előre megoldottuk, de lehet, hogy nem jól.
/// Az üres string reprezentációja nem szerencsés, mert így NULL pointerré
/// konvertál a c_str(), ami külön kezelést igényel a későbbiekben, így
/// a teszt program sem fogadja el.
/// Gondolja végig, és változtassa meg!
/// Két lehetőség van:
///     a) nem NULL pointert tárol, hanem téynlegesen üres sringet.
///     b) a c_str() üres stringet ad vissza
/// Bármelyik jó, mert ez az osztály belügye.

    size_t size() const { return len; }


    /// Default konstruktor:
    String() :pData(0), len(0) {}

    /// C-stringet ad vissza
    const char* c_str() const { if (pData) return pData; else return "";}

    /// Konstruktor: egy char karakterből (createStrFromChar)
    String(char ch);

    /// Konstruktor: egy nullával lezárt char sorozatból (createStringFromCharStr)
    String(const char *p);

    /// MÁSOLÓ konstruktor, ami a createStringFromString-ből keletkezett
    /// @param s1 - String, amiből létrehozzuk az új String-et
    String(const String& s1);

    /// Destruktor (disposeString)
    ~String() { delete[] pData; }




    /// Egyéb tagfüggvények:
    /// Kiírunk egy Stringet (debug célokra) (ez kész)
    /// Elötte kiírunk egy tetszőleges szöveget.
    /// @param txt - nullával lezárt szövegre mutató pointer
    void printDbg(const char *txt = "") const {
        std::cout << txt << "[" << len << "], "
                  << (pData ? pData : "(NULL)") << std::endl;
    }

    /// Operátorok:
    /// Értékadó operátor is kell !
    /// @param rhs_s - jobboldali String
    /// @return baoldali (módosított) string (referenciája)
    String& operator=(const String& rhs_s);

    String& operator+=(const String& rhs_s) {
        *this = *this + rhs_s;
        return *this;
    }

    bool operator==(const String& rhs_s) {
        if (len == rhs_s.size()){
            for (int i = 0; i < len; ++i) {
                if (pData[i] != rhs_s[i]){
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    bool operator!=(const String& rhs_s) {
        if (len == rhs_s.size()){
            for (int i = 0; i < len; ++i) {
                if (pData[i] == rhs_s[i]){
                    return false;
                }
            }
            return true;
        }
        return true;
    }


    /// Két Stringet összefűz (concatString)
    /// @param rhs_s - jobboldali String
    /// @return új String, ami tartalmazza a két stringet egmás után
    String operator+(const String& rhs_s) const ;

    /// Sztrinhez karaktert összefűz (concatString)
    /// @param rhs_c - jobboldali karakter
    /// @return új String, ami tartalmazza a két sztringet egymás után
    String operator+(char rhs_c) const { return *this + String(rhs_c);}

    /// A string egy megadott indexű elemének REFERENCIÁJÁVAL tér vissza.
    /// charAtString-ből keletkezett, de ezt bal oldalon is lehet használni
    /// @param idx - charakter indexe
    /// @return karakter (referencia)
    ///         Indexelési hiba esetén const char* kivételt dob (assert helyett).
    char& operator[](unsigned int idx);

    /// A string egy megadott indexű elemének REFERENCIÁJÁVAL tér vissza.
    /// charAtString-ből keletkezett. Konstans stringre alkalmazható.
    /// Indexelési hiba esetén const char* kivételt dob (assert helyett).
    /// @param idx - karakter indexe
    /// @return karakter (referencia)
    ///         Indexelési hiba esetén const char* kivételt dob (assert helyett).
    const char& operator[](unsigned int idx) const;

    void erase() { *this = ""; }
};

/// Globális függvények:
/// kiír az ostream-re (printString)
/// Nem célszerű using-ot használni, mert ez egy include file. Így ki kell írni az std::-t
/// @param os - ostream típusú objektum
/// @param s0 - String, amit kiírunk
/// @return os
/// Vigyázat nem tagfüggvény! Nem is tűnik el az s0 !
/// Nem kell, hogy barát legyen, mert a c_str() segít
std::ostream& operator<<(std::ostream& os, const String& s0);

/// Beolvas az istream-ről egy szót egy string-be.
/// @param is - istream típusú objektum
/// @param s0 - String, amibe beolvas
/// @return is
/// Vigyázat nem tagfüggvény! Nem is tűnik el az s0 !
/// Nem kell, hogy barát legyen mert van Str + ch
std::istream& operator>>(std::istream& is, String& s0);


/// String operator+(char ch, const String& str);
/// Vagy inline, vagy nem itt a helye!
/// Nem kell, hogy barát legyen mert tudunk chr-ből str-be konvertálni
/// két str pedig összeadható
inline String operator+(char ch, const String& str) { return String(ch) + str; }

#endif

