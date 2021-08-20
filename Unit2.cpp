//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "main.h"
//#include "main.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SpeedButton2Click(TObject *Sender)
{
  Close();        
}
//---------------------------------------------------------------------------
void __fastcall TForm2::SpeedButton1Click(TObject *Sender)
{
char stat[6];
stat[0]=CSpinEdit1->Value;
stat[1]=CSpinEdit2->Value;
stat[2]=CSpinEdit3->Value;
stat[3]=CSpinEdit4->Value;
stat[4]=CSpinEdit5->Value;
stat[5]=CSpinEdit6->Value;
Form1->statystyka.AddStat(stat);
Form1->statystyka.ReLoadData();
Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::FormActivate(TObject *Sender)
{
CSpinEdit1->Value=Form1->tab[0].num;
CSpinEdit2->Value=Form1->tab[1].num;
CSpinEdit3->Value=Form1->tab[2].num;
CSpinEdit4->Value=Form1->tab[3].num;
CSpinEdit5->Value=Form1->tab[4].num;
CSpinEdit6->Value=Form1->tab[5].num;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::FormCanResize(TObject *Sender, int &NewWidth,
      int &NewHeight, bool &Resize)
{
Resize=false;        
}
//---------------------------------------------------------------------------

