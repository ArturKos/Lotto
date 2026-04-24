//---------------------------------------------------------------------------
#ifndef StatystykaH
#define StatystykaH
//---------------------------------------------------------------------------

#include <vector>

// Nazwa pliku z binarna historia losowan (kazdy rekord = 6 bajtow: liczby 1..49).
extern const char * const NAZWA_PLIKU_STATYSTYKI;

// Pojedyncze losowanie: 6 liczb z zakresu 1..49.
struct Losowanie {
 unsigned char liczby[6];
};

// Jeden wpis rankingu liczb: numer liczby (1..49) oraz ile razy sie pojawila.
struct WpisRankingu {
 unsigned char num;
 unsigned int  razy;
};

// Gromadzi liczniki wystapien liczb 1..49 oraz ranking malejaco wg czestosci,
// budowane na podstawie pliku z historia losowan.
class KolektorStatystyk {
private:
 unsigned int licznikWystapien[49];
 unsigned int liczbaLosowan;
 std::vector<Losowanie> historia;
 WpisRankingu ranking[49];

 // Sortuje ranking malejaco wg liczby wystapien.
 void przelczRanking();
public:
 KolektorStatystyk();

 // Wczytuje cala historie z pliku i przelicza liczniki oraz ranking.
 void WczytajDane();

 // Dopisuje 6 liczb nowego losowania do pliku i aktualizuje liczniki oraz ranking.
 // Odrzuca wpis jesli ktorakolwiek liczba jest spoza zakresu 1..49.
 void DodajLosowanie(const unsigned char losowanie[6]);

 // Zwraca ile razy wylosowano liczbe o indeksie i (0..48). 0 gdy indeks poza zakresem.
 unsigned int PobierzLicznik(int i) const;

 // Zwraca calkowita liczbe wczytanych losowan.
 unsigned int PobierzLiczbeLosowan() const;

 // Zwraca tablice 49 wpisow rankingu, posortowana malejaco wg razy.
 const WpisRankingu* PobierzRanking() const;

 // Zwraca historie wszystkich losowan (kolejnosc jak w pliku).
 const std::vector<Losowanie>& PobierzWszystkieLosowania() const;
};

//---------------------------------------------------------------------------
#endif
