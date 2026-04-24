//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("OknoGlowne.cpp", OknoGlowne);
USEFORM("OknoDodajWynik.cpp", OknoDodajWynik);
USEFORM("OknoSzczegolyStatystyk.cpp", OknoSzczegolyStatystyk);
USEFORM("OknoGenerator.cpp", OknoGenerator);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TOknoGlowne), &OknoGlowne);
                 Application->CreateForm(__classid(TOknoDodajWynik), &OknoDodajWynik);
                 Application->CreateForm(__classid(TOknoSzczegolyStatystyk), &OknoSzczegolyStatystyk);
                 Application->CreateForm(__classid(TOknoGenerator), &OknoGenerator);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
