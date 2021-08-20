//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------






void __fastcall TForm3::FormActivate(TObject *Sender)
{
v1->Strings->Clear();
v2->Strings->Clear();
v3->Strings->Clear();
int i;
AnsiString s;
for(i=0;i<49;i++)
 {
  s=i+1;s+='=';s+=Form1->statystyka.GetNum(i);
  v1->Strings->Add(s);
  }
for(i=0;i<49;i++)
 {
  s=Form1->tab[i].num;s+='=';s+=Form1->tab[i].razy;
  v2->Strings->Add(s);
  }
int k;
for(i=0;i<49;i++)
 {
  k=Form1->statystyka.IloscLosowan()/Form1->statystyka.GetNum(i);
  s=i+1;s+='=';s+=k;
  v3->Strings->Add(s);
  }
ListBox1->Items->Clear();
AnsiString nazwa_pliku;
        nazwa_pliku = "Statystyka.lot";
        FILE *stream;
        if ((stream = fopen(nazwa_pliku.c_str(), "rb"))!= NULL)
          {
            AnsiString s;
            char buf[6];
            while(!feof(stream))
              {
                  fread(buf,6,1,stream);
                  s="";
                  for(int i = 0;i <=5;i++){
                      s+=int(buf[i]);s+=",";}
                  ListBox1->Items->Add(s);
                  if(filesize(stream)-ftell(stream)<6)break;
             };
            fclose(stream);
          }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::SpeedButton1Click(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormCanResize(TObject *Sender, int &NewWidth,
      int &NewHeight, bool &Resize)
{
Resize=false;
}
//---------------------------------------------------------------------------

