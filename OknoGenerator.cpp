//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdlib.h>
#pragma hdrstop

#include "OknoGenerator.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TOknoGenerator *OknoGenerator;

// Losuje 6 roznych liczb z zakresu 1..49 metoda Fishera-Yatesa i wpisuje je do pol okna.
void wylosujKupon()
{
 int pula[49];
 for(int i = 0; i < 49; i++) pula[i] = i + 1;
 for(int i = 0; i < 6; i++)
  {
   int j = i + rand() % (49 - i);
   int tmp = pula[i]; pula[i] = pula[j]; pula[j] = tmp;
  }
 OknoGenerator->PoleLiczby1->Text = pula[0];
 OknoGenerator->PoleLiczby2->Text = pula[1];
 OknoGenerator->PoleLiczby3->Text = pula[2];
 OknoGenerator->PoleLiczby4->Text = pula[3];
 OknoGenerator->PoleLiczby5->Text = pula[4];
 OknoGenerator->PoleLiczby6->Text = pula[5];
}
//---------------------------------------------------------------------------
__fastcall TOknoGenerator::TOknoGenerator(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

// Wykonuje pierwsze losowanie zaraz po otwarciu okna.
void __fastcall TOknoGenerator::FormCreate(TObject *Sender)
{
 wylosujKupon();
}
//---------------------------------------------------------------------------

// Losuje nowy kupon po klikniecu przycisku "Losuj".
void __fastcall TOknoGenerator::PrzyciskLosujClick(TObject *Sender)
{
 wylosujKupon();
}
//---------------------------------------------------------------------------

// Cyklicznie losuje nowy kupon - wywolywane przez TimerLosowania.
void __fastcall TOknoGenerator::TimerLosowaniaTimer(TObject *Sender)
{
 wylosujKupon();
}
//---------------------------------------------------------------------------

// Wlacza/wylacza ciagle losowanie z podmiana napisu przycisku.
void __fastcall TOknoGenerator::PrzyciskCzasoweClick(TObject *Sender)
{
 if(TimerLosowania->Enabled)
  {
   PrzyciskCzasowe->Caption = "Czasowe...";
   TimerLosowania->Enabled = false;
  }
 else
  {
   PrzyciskCzasowe->Caption = "Stop";
   TimerLosowania->Enabled = true;
  }
}
//---------------------------------------------------------------------------
