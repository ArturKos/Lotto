//---------------------------------------------------------------------------

#ifndef OknoSzczegolyStatystykH
#define OknoSzczegolyStatystykH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ValEdit.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TOknoSzczegolyStatystyk : public TForm
{
__published:	// IDE-managed Components
        TValueListEditor *ListaWgKolejnosci;
        TValueListEditor *ListaWgCzestosci;
        TSpeedButton *PrzyciskOk;
        TListBox *ListaLosowan;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TValueListEditor *ListaWgOkresu;
        TLabel *Label4;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall PrzyciskOkClick(TObject *Sender);
        void __fastcall FormCanResize(TObject *Sender, int &NewWidth,
          int &NewHeight, bool &Resize);
private:	// User declarations
public:		// User declarations
        __fastcall TOknoSzczegolyStatystyk(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOknoSzczegolyStatystyk *OknoSzczegolyStatystyk;
//---------------------------------------------------------------------------
#endif
