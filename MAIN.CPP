//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#include <io.h>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#pragma hdrstop

#include "main.h"
#include "unit2.h"
#include "unit3.h"
#include "unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;


const szer=16;
      color[7]= { clTeal,clSkyBlue,clGreen,clWhite,clInfoBk,clYellow,clLime  };
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Dodaj1Click(TObject *Sender)
{
  Form2->ShowModal();        
}
//---------------------------------------------------------------------------
void init()
{
int i,z=48,j;
struct liczba tmp;
for(i=0;i<49;i++)
 {
  tmp.num=i+1;
  tmp.razy=Form1->statystyka.GetNum(i);
  Form1->tab[i]=tmp;
 }
 i=0;
while(i<z)
 {
   for(j=0;j<z;j++)
      if(Form1->tab[j].razy<Form1->tab[j+1].razy)
       {
        tmp = Form1->tab[j+1];
        Form1->tab[j+1]=Form1->tab[j];
        Form1->tab[j]=tmp;
       }
   z--;
 }
}
int obetnij()
{
 int M=0;
 for(int i=0;i<49;i++)
  if(M<Form1->statystyka.GetNum(i)) M=Form1->statystyka.GetNum(i);
 int m=M;
  for(int i=0;i<49;i++)
  if(m>Form1->statystyka.GetNum(i)) m=Form1->statystyka.GetNum(i);
/*if((M>Form1->PaintBox1->Height)&&
  (M-Form1->PaintBox1->Height<m))
return M-Form1->PaintBox1->Height;   */
return m;
}
void __fastcall TForm1::FormPaint(TObject *Sender)

{
int i;
int rozmiar=obetnij();
for(i=0;i<49;i++)
 {
  PaintBox1->Canvas->Brush->Color=color[i%7];
  PaintBox1->Canvas->Rectangle(i*szer,PaintBox1->Height-(statystyka.GetNum(i)+5)+rozmiar,i*szer+szer,PaintBox1->Height);
  PaintBox1->Canvas->Brush->Color=Form1->Color;
  PaintBox1->Canvas->TextOutA(i*szer+2,PaintBox1->Height-(statystyka.GetNum(i)+5)-15+rozmiar,i+1);
 }
init();
AnsiString s;
for(int i = 0;i<49;i++)
 {
   s=s+tab[i].num+',';
 }
Label2->Caption=s;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCanResize(TObject *Sender, int &NewWidth,
      int &NewHeight, bool &Resize)
{
Resize = false;        
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Panel1Click(TObject *Sender)
{
  statystyka.ReLoadData();
  Form3->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::PaintBox1MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
  AnsiString s;
  s="Liczba "; s+=X/szer+1; s+=" powtórzy³a siê ";
  s+=statystyka.GetNum(X/szer);s+=" razy.";
  s+=" Œrednio co ";s+=statystyka.IloscLosowan()/statystyka.GetNum(X/szer);
  s+=" losowañ."; s+=" Na ";s+=statystyka.IloscLosowan();
  s+=" losowañ.";
  StatusBar1->Panels->Items[0]->Text=s;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
Randomize();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Losowanie1Click(TObject *Sender)
{
Form4->ShowModal();
}
//---------------------------------------------------------------------------

