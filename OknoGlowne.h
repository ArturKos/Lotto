//---------------------------------------------------------------------------

#ifndef OknoGlowneH
#define OknoGlowneH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include <ExtCtrls.hpp>

#include "Statystyka.h"
//---------------------------------------------------------------------------

class TOknoGlowne : public TForm
{
__published:	// IDE-managed Components
        TStatusBar *StatusBar1;
        TToolBar *ToolBar1;
        TMainMenu *MainMenu1;
        TMenuItem *MenuStatystyka;
        TMenuItem *MenuDodajWynik;
        TPanel *PanelNajczestszych;
        TPaintBox *WykresLosowan;
        TLabel *Label1;
        TLabel *EtykietaRanking;
        TMenuItem *MenuLosowanie;
        void __fastcall MenuDodajWynikClick(TObject *Sender);
        void __fastcall FormPaint(TObject *Sender);
        void __fastcall FormCanResize(TObject *Sender, int &NewWidth,
          int &NewHeight, bool &Resize);
        void __fastcall PanelNajczestszychClick(TObject *Sender);
        void __fastcall WykresLosowanMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall MenuLosowanieClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	KolektorStatystyk statystyka;
        __fastcall TOknoGlowne(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOknoGlowne *OknoGlowne;
//---------------------------------------------------------------------------
#endif
