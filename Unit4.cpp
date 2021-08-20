//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;

void losuj()
{
 Form4->Edit1->Text = (rand()%49)+1;
 Form4->Edit2->Text = (rand()%49)+1;
 Form4->Edit3->Text = (rand()%49)+1;
 Form4->Edit4->Text = (rand()%49)+1;
 Form4->Edit5->Text = (rand()%49)+1;
 Form4->Edit6->Text = (rand()%49)+1;
}
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormCreate(TObject *Sender)
{
randomize();
losuj();       
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
losuj();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Timer1Timer(TObject *Sender)
{
losuj();        
}
//---------------------------------------------------------------------------
void __fastcall TForm4::BitBtn1Click(TObject *Sender)
{
if(Timer1->Enabled)
 {
  BitBtn1->Caption="Czasowe...";
  Timer1->Enabled=false;
 }else
 {
  BitBtn1->Caption="Stop";
  Timer1->Enabled=true;
 }

}
//---------------------------------------------------------------------------
