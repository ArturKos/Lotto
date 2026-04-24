//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "OknoDodajWynik.h"
#include "OknoGlowne.h"
//#include "main.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TOknoDodajWynik *OknoDodajWynik;
//---------------------------------------------------------------------------
__fastcall TOknoDodajWynik::TOknoDodajWynik(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

// Zamyka okno bez zapisywania wyniku.
void __fastcall TOknoDodajWynik::PrzyciskAnulujClick(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------

// Odczytuje 6 liczb z pol, dopisuje je do pliku statystyk i zamyka okno.
void __fastcall TOknoDodajWynik::PrzyciskOkClick(TObject *Sender)
{
 unsigned char nowyWynik[6];
 nowyWynik[0] = (unsigned char)PoleLiczby1->Value;
 nowyWynik[1] = (unsigned char)PoleLiczby2->Value;
 nowyWynik[2] = (unsigned char)PoleLiczby3->Value;
 nowyWynik[3] = (unsigned char)PoleLiczby4->Value;
 nowyWynik[4] = (unsigned char)PoleLiczby5->Value;
 nowyWynik[5] = (unsigned char)PoleLiczby6->Value;
 OknoGlowne->statystyka.DodajLosowanie(nowyWynik);
 Close();
}
//---------------------------------------------------------------------------

// Przy otwarciu okna wypelnia pola 6 najczestszymi liczbami z rankingu.
void __fastcall TOknoDodajWynik::FormActivate(TObject *Sender)
{
 const WpisRankingu* ranking = OknoGlowne->statystyka.PobierzRanking();
 PoleLiczby1->Value = ranking[0].num;
 PoleLiczby2->Value = ranking[1].num;
 PoleLiczby3->Value = ranking[2].num;
 PoleLiczby4->Value = ranking[3].num;
 PoleLiczby5->Value = ranking[4].num;
 PoleLiczby6->Value = ranking[5].num;
}
//---------------------------------------------------------------------------

// Blokuje zmiane rozmiaru okna dialogowego.
void __fastcall TOknoDodajWynik::FormCanResize(TObject *Sender, int &NewWidth,
      int &NewHeight, bool &Resize)
{
 Resize = false;
}
//---------------------------------------------------------------------------

