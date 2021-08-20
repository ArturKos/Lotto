//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include <stdio.h>
#include <io.h>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
long filesize(FILE *stream)
{
   long curpos, length;

   curpos = ftell(stream);
   fseek(stream, 0L, SEEK_END);
   length = ftell(stream);
   fseek(stream, curpos, SEEK_SET);
   return length;

}
class stat
 {
   private:
     unsigned long int liczby[49];
     AnsiString nazwa_pliku;
     unsigned long int losowan;
   public:
     void ReLoadData()
     {
        for(int i = 0;i<49;i++)
          liczby[i]=0;
        nazwa_pliku = "Statystyka.lot";
        FILE *stream;
        if ((stream = fopen(nazwa_pliku.c_str(), "rb"))!= NULL)
          {
            char buf[6];
            losowan=0;
            while(!feof(stream))
              {
                  losowan++;
                  fread(buf,6,1,stream);
                  for(int i = 0;i <=5;i++)
                    liczby[int(buf[i]-1)]++;
                  if(filesize(stream)-ftell(stream)<6)break;
             }
            fclose(stream);
          }
     }
     void AddStat(char stat[6])
       {
              FILE *stream;
              if ((stream = fopen(nazwa_pliku.c_str(), "ab"))!= NULL)
                 {
                     fwrite(stat, 6, 1, stream);
                     fclose(stream);
                     losowan++;
                 }
       }
     unsigned long int GetNum(int i)
      {
        return liczby[i];
      }
     unsigned long int IloscLosowan()
     {
      return losowan;
     }
     stat()
      {
        losowan=0;
        for(int i = 0;i<49;i++)
          liczby[i]=0;
        nazwa_pliku = "Statystyka.lot";
        FILE *stream;
        if ((stream = fopen(nazwa_pliku.c_str(), "rb"))!= NULL)
          {
            char buf[6];
            while(!feof(stream))
              {
                  losowan++;
                  fread(buf,6,1,stream);
                  for(int i = 0;i <=5;i++)
                    liczby[int(buf[i])-1]++;
                  if(filesize(stream)-ftell(stream)<6)break;
             }
            fclose(stream);
          }
      };
 };
struct liczba{
int num,razy;};
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TStatusBar *StatusBar1;
        TToolBar *ToolBar1;
        TMainMenu *MainMenu1;
        TMenuItem *Statystyka1;
        TMenuItem *Dodaj1;
        TPanel *Panel1;
        TPaintBox *PaintBox1;
        TLabel *Label1;
        TLabel *Label2;
        TMenuItem *Losowanie1;
        void __fastcall Dodaj1Click(TObject *Sender);
        void __fastcall FormPaint(TObject *Sender);
        void __fastcall FormCanResize(TObject *Sender, int &NewWidth,
          int &NewHeight, bool &Resize);
        void __fastcall Panel1Click(TObject *Sender);
        void __fastcall PaintBox1MouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Losowanie1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	stat statystyka;
        struct liczba tab[49];
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
