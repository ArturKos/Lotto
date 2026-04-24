//---------------------------------------------------------------------------

#ifndef OknoDodajWynikH
#define OknoDodajWynikH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CSPIN.h"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TOknoDodajWynik : public TForm
{
__published:	// IDE-managed Components
        TCSpinEdit *PoleLiczby1;
        TSpeedButton *PrzyciskOk;
        TSpeedButton *PrzyciskAnuluj;
        TCSpinEdit *PoleLiczby2;
        TCSpinEdit *PoleLiczby3;
        TCSpinEdit *PoleLiczby4;
        TCSpinEdit *PoleLiczby5;
        TCSpinEdit *PoleLiczby6;
        void __fastcall PrzyciskAnulujClick(TObject *Sender);
        void __fastcall PrzyciskOkClick(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall FormCanResize(TObject *Sender, int &NewWidth,
          int &NewHeight, bool &Resize);
private:	// User declarations
public:		// User declarations
        __fastcall TOknoDodajWynik(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOknoDodajWynik *OknoDodajWynik;
//---------------------------------------------------------------------------
#endif
