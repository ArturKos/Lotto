//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "OknoGlowne.h"
#include "OknoDodajWynik.h"
#include "OknoSzczegolyStatystyk.h"
#include "OknoGenerator.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TOknoGlowne *OknoGlowne;

// Szerokosc pojedynczego slupka na wykresie wystapien (piksele).
const int SZEROKOSC_SLUPKA = 16;
// Paleta kolorow dla slupkow - wybierane cyklicznie.
const TColor KOLORY_SLUPKOW[7] = { clTeal, clSkyBlue, clGreen, clWhite, clInfoBk, clYellow, clLime };

// Teksty paska statusu - CP1250 (plik zrodlowy w tym kodowaniu).
static const char* const STR_LICZBA        = "Liczba ";
static const char* const STR_POWTORZYLA    = " powtórzy³a siê ";
static const char* const STR_RAZY          = " razy.";
static const char* const STR_SREDNIO_CO    = " œrednio co ";
static const char* const STR_LOSOWAN       = " losowañ.";
static const char* const STR_NA            = " Na ";
//---------------------------------------------------------------------------
__fastcall TOknoGlowne::TOknoGlowne(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

// Otwiera okno dialogowe do dopisania nowego losowania.
void __fastcall TOknoGlowne::MenuDodajWynikClick(TObject *Sender)
{
  OknoDodajWynik->ShowModal();
}
//---------------------------------------------------------------------------

// Zwraca najmniejsza liczbe wystapien po 49 liczbach - uzywana jako dolna podstawa skali wykresu.
int wyznaczMinimumSkali()
{
 unsigned long int maks = 0;
 for(int i = 0; i < 49; i++)
   if(maks < OknoGlowne->statystyka.PobierzLicznik(i))
     maks = OknoGlowne->statystyka.PobierzLicznik(i);
 unsigned long int min = maks;
 for(int i = 0; i < 49; i++)
   if(min > OknoGlowne->statystyka.PobierzLicznik(i))
     min = OknoGlowne->statystyka.PobierzLicznik(i);
 return (int)min;
}
// Rysuje wykres slupkowy z liczba wystapien kazdej liczby i uzupelnia etykiete rankingu.
void __fastcall TOknoGlowne::FormPaint(TObject *Sender)
{
 int podstawa = wyznaczMinimumSkali();
 for(int i = 0; i < 49; i++)
  {
   int lewyX  = i * SZEROKOSC_SLUPKA;
   int prawyX = (i + 1) * SZEROKOSC_SLUPKA;
   int gornyY = WykresLosowan->Height - (statystyka.PobierzLicznik(i) + 5) + podstawa;
   WykresLosowan->Canvas->Brush->Color = KOLORY_SLUPKOW[i % 7];
   WykresLosowan->Canvas->Rectangle(lewyX, gornyY, prawyX, WykresLosowan->Height);
   WykresLosowan->Canvas->Brush->Color = OknoGlowne->Color;
   WykresLosowan->Canvas->TextOutA(lewyX + 2, gornyY - 15, i + 1);
  }
 const WpisRankingu* ranking = statystyka.PobierzRanking();
 AnsiString opisRankingu;
 for(int i = 0; i < 49; i++)
   opisRankingu = opisRankingu + (int)ranking[i].num + ',';
 EtykietaRanking->Caption = opisRankingu;
}
//---------------------------------------------------------------------------


// Blokuje zmiane rozmiaru okna - okno ma stale wymiary.
void __fastcall TOknoGlowne::FormCanResize(TObject *Sender, int &NewWidth,
      int &NewHeight, bool &Resize)
{
 Resize = false;
}
//---------------------------------------------------------------------------

// Odswieza statystyki z pliku i otwiera okno ze szczegolami.
void __fastcall TOknoGlowne::PanelNajczestszychClick(TObject *Sender)
{
 statystyka.WczytajDane();
 OknoSzczegolyStatystyk->ShowModal();
}
//---------------------------------------------------------------------------


// Wyswietla w pasku statusu informacje o liczbie, nad ktora przesuwa sie mysz.
void __fastcall TOknoGlowne::WykresLosowanMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
 int indeksLiczby = X / SZEROKOSC_SLUPKA;
 if(indeksLiczby < 0 || indeksLiczby > 48) return;
 unsigned long int razy = statystyka.PobierzLicznik(indeksLiczby);
 AnsiString opis;
 opis = STR_LICZBA; opis += indeksLiczby + 1; opis += STR_POWTORZYLA;
 opis += razy; opis += STR_RAZY;
 if(razy > 0)
  {
   opis += STR_SREDNIO_CO; opis += statystyka.PobierzLiczbeLosowan() / razy;
   opis += STR_LOSOWAN;
  }
 opis += STR_NA; opis += statystyka.PobierzLiczbeLosowan();
 opis += STR_LOSOWAN;
 StatusBar1->Panels->Items[0]->Text = opis;
}
//---------------------------------------------------------------------------

// Inicjalizuje globalny generator liczb pseudolosowych (wspolny dla calego procesu,
// uzywany rowniez przez wylosujKupon() w oknie generatora).
void __fastcall TOknoGlowne::FormCreate(TObject *Sender)
{
 Randomize();
}
//---------------------------------------------------------------------------

// Otwiera okno z generatorem losowan.
void __fastcall TOknoGlowne::MenuLosowanieClick(TObject *Sender)
{
 OknoGenerator->ShowModal();
}
//---------------------------------------------------------------------------

