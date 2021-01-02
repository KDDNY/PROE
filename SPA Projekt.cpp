#include <wx/wx.h>
#include "Program.h"
#include "Okno.h"
#include "Dodawanie.h"


class MyApp: public wxApp
{
public:
    bool OnInit() {
        Program p;
        p.uruchom();
     //   Okno* okno = new Okno("SPA", wxPoint(50, 50), wxSize(800, 600), p.spa);
     //   okno->Show(true);
        Dodawanie* dodawanie = new Dodawanie(wxPoint(50, 50));
        dodawanie->Show(true);
        return true;
    }
};
wxIMPLEMENT_APP(MyApp);
