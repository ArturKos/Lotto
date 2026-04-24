//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <fstream>
#include "Statystyka.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

const char * const NAZWA_PLIKU_STATYSTYKI = "Statystyka.lot";

KolektorStatystyk::KolektorStatystyk() : liczbaLosowan(0) {
 for (int i = 0; i < 49; i++) licznikWystapien[i] = 0;
 WczytajDane();
}

void KolektorStatystyk::WczytajDane() {
 liczbaLosowan = 0;
 for (int i = 0; i < 49; i++) licznikWystapien[i] = 0;
 historia.clear();

 std::ifstream plik(NAZWA_PLIKU_STATYSTYKI, std::ios::binary);
 if (plik) {
   Losowanie wpis;
   while (plik.read(reinterpret_cast<char*>(wpis.liczby), 6)) {
     bool poprawny = true;
     for (int i = 0; i < 6; i++)
       if (wpis.liczby[i] < 1 || wpis.liczby[i] > 49) { poprawny = false; break; }
     if (!poprawny) continue;
     historia.push_back(wpis);
     liczbaLosowan++;
     for (int i = 0; i < 6; i++)
       licznikWystapien[wpis.liczby[i] - 1]++;
   }
 }
 przelczRanking();
}

void KolektorStatystyk::DodajLosowanie(const unsigned char losowanie[6]) {
 for (int i = 0; i < 6; i++)
   if (losowanie[i] < 1 || losowanie[i] > 49) return;

 std::ofstream plik(NAZWA_PLIKU_STATYSTYKI, std::ios::binary | std::ios::app);
 if (!plik) return;
 plik.write(reinterpret_cast<const char*>(losowanie), 6);
 plik.close();

 Losowanie wpis;
 for (int i = 0; i < 6; i++) wpis.liczby[i] = losowanie[i];
 historia.push_back(wpis);
 liczbaLosowan++;
 for (int i = 0; i < 6; i++)
   licznikWystapien[losowanie[i] - 1]++;
 przelczRanking();
}

unsigned int KolektorStatystyk::PobierzLicznik(int i) const {
 if (i < 0 || i >= 49) return 0;
 return licznikWystapien[i];
}

unsigned int KolektorStatystyk::PobierzLiczbeLosowan() const {
 return liczbaLosowan;
}

const WpisRankingu* KolektorStatystyk::PobierzRanking() const {
 return ranking;
}

const std::vector<Losowanie>& KolektorStatystyk::PobierzWszystkieLosowania() const {
 return historia;
}

void KolektorStatystyk::przelczRanking() {
 for (int i = 0; i < 49; i++) {
   ranking[i].num  = (unsigned char)(i + 1);
   ranking[i].razy = licznikWystapien[i];
 }
 for (int pass = 0; pass < 48; pass++)
   for (int j = 0; j < 48 - pass; j++)
     if (ranking[j].razy < ranking[j + 1].razy) {
       WpisRankingu tmp = ranking[j + 1];
       ranking[j + 1]   = ranking[j];
       ranking[j]       = tmp;
     }
}
