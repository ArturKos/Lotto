//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "OknoSzczegolyStatystyk.h"
#include "OknoGlowne.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TOknoSzczegolyStatystyk *OknoSzczegolyStatystyk;
//---------------------------------------------------------------------------
__fastcall TOknoSzczegolyStatystyk::TOknoSzczegolyStatystyk(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

// Przy otwarciu okna uzupelnia trzy listy statystyk oraz wykaz wszystkich losowan.
void __fastcall TOknoSzczegolyStatystyk::FormActivate(TObject *Sender)
{
 const KolektorStatystyk& stat = OknoGlowne->statystyka;
 const WpisRankingu* ranking = stat.PobierzRanking();

 ListaWgKolejnosci->Strings->Clear();
 ListaWgCzestosci->Strings->Clear();
 ListaWgOkresu->Strings->Clear();
 AnsiString wiersz;
 for(int i = 0; i < 49; i++)
  {
   wiersz = i + 1; wiersz += '='; wiersz += stat.PobierzLicznik(i);
   ListaWgKolejnosci->Strings->Add(wiersz);
  }
 for(int i = 0; i < 49; i++)
  {
   wiersz = (int)ranking[i].num; wiersz += '='; wiersz += ranking[i].razy;
   ListaWgCzestosci->Strings->Add(wiersz);
  }
 for(int i = 0; i < 49; i++)
  {
   unsigned int razy = stat.PobierzLicznik(i);
   wiersz = i + 1; wiersz += '=';
   if(razy > 0)
     wiersz += stat.PobierzLiczbeLosowan() / razy;
   else
     wiersz += "-";
   ListaWgOkresu->Strings->Add(wiersz);
  }
 ListaLosowan->Items->Clear();
 const std::vector<Losowanie>& historia = stat.PobierzWszystkieLosowania();
 for(unsigned int i = 0; i < historia.size(); i++)
  {
   AnsiString losowanie = "";
   for(int j = 0; j < 6; j++)
    {
     losowanie += (int)historia[i].liczby[j]; losowanie += ",";
    }
   ListaLosowan->Items->Add(losowanie);
  }
}
//---------------------------------------------------------------------------

// Zamyka okno ze statystykami.
void __fastcall TOknoSzczegolyStatystyk::PrzyciskOkClick(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------

// Blokuje zmiane rozmiaru okna.
void __fastcall TOknoSzczegolyStatystyk::FormCanResize(TObject *Sender, int &NewWidth,
      int &NewHeight, bool &Resize)
{
 Resize = false;
}
//---------------------------------------------------------------------------

