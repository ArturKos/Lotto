//---------------------------------------------------------------------------

#ifndef OknoGeneratorH
#define OknoGeneratorH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TOknoGenerator : public TForm
{
__published:	// IDE-managed Components
        TButton *PrzyciskLosuj;
        TEdit *PoleLiczby1;
        TEdit *PoleLiczby2;
        TEdit *PoleLiczby3;
        TEdit *PoleLiczby4;
        TEdit *PoleLiczby5;
        TEdit *PoleLiczby6;
        TBitBtn *PrzyciskCzasowe;
        TTimer *TimerLosowania;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall PrzyciskLosujClick(TObject *Sender);
        void __fastcall TimerLosowaniaTimer(TObject *Sender);
        void __fastcall PrzyciskCzasoweClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TOknoGenerator(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOknoGenerator *OknoGenerator;
//---------------------------------------------------------------------------
#endif
