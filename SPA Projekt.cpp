#include <wx/wx.h>
#include "Program.h"
#include "Okno.h"

class MyApp: public wxApp
{
public:
    bool OnInit() {
        Program p;
        p.uruchom();
        Okno* okno = new Okno("SPA", wxPoint(50, 50), wxSize(800, 600), p.spa);
        okno->Show(true);
        return true;
    }
};
wxIMPLEMENT_APP(MyApp);
