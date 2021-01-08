#include "Dodawanie.h"
#include "SPA.h"


Dodawanie::Dodawanie(wxPoint pos, SPA* spa, Okno* okno)
    : spa(spa), okno(okno), wxFrame(nullptr, wxID_ANY, "SPA", pos, wxSize(240, 410))
{
    wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* vbox2 = new wxBoxSizer(wxVERTICAL);

    int id = obliczID();
    wxStaticText* st1 = new wxStaticText(this, wxID_ANY, wxT("Dodaj now¹ osobê:"));
    wxStaticText* st2 = new wxStaticText(this, wxID_ANY, wxT("ID: " + std::to_string(id)));
    wxStaticText* st3 = new wxStaticText(this, wxID_ANY, wxT("Imiê:"));
    tc1 = new wxTextCtrl(this, wxID_ANY);
    wxStaticText* st9 = new wxStaticText(this, wxID_ANY, wxT("Nazwisko:"));
    tc2 = new wxTextCtrl(this, wxID_ANY);


    wxArrayString choices3;
    choices3.Add("Standard");
    choices3.Add("Standard Family");
    choices3.Add("VIP");
    choices3.Add("Penthouse");
    radioBox3 = new wxRadioBox(this, wxID_ANY, "Zakwaterowanie", wxDefaultPosition, wxDefaultSize, choices3, 4, wxRA_VERTICAL);

    wxArrayString choices2;
    choices2.Add("tak");
    choices2.Add("nie");
    radioBox2 = new wxRadioBox(this, wxID_ANY, "Zwierzêta", wxDefaultPosition, wxDefaultSize, choices2, 2, wxRA_VERTICAL);

    wxArrayString choices;
    choices.Add("na miejscu");
    choices.Add("online");
    radioBox1 = new wxRadioBox(this, wxID_ANY, "P³atnoœæ", wxDefaultPosition, wxDefaultSize, choices, 2, wxRA_VERTICAL);


    wxArrayString choices4;
    choices4.Add("3posilki");
    choices4.Add("5posilkow");
    choices4.Add("roomservice");
    radioBox4 = new wxRadioBox(this, wxID_ANY, "Wy¿ywienie", wxDefaultPosition, wxDefaultSize, choices4, 3, wxRA_VERTICAL);
    

    wxStaticText* st8 = new wxStaticText(this, wxID_ANY, wxT("Us³ugi:"));
    tc3 = new wxTextCtrl(this, wxID_ANY);

    wxButton* btn1 = new wxButton(this, 1, wxT("ZatwierdŸ"));
    wxButton* btn2 = new wxButton(this, 2, wxT("Anuluj"));



    vbox->Add(st1, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 5);
    vbox->Add(st2, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 5);
    vbox->Add(st9, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 5);
    vbox->Add(tc1, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 5);
    vbox->Add(st3, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 5);
    vbox->Add(tc2, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 5);
    vbox->Add(st8, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 5);
    vbox->Add(tc3, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 5);
    vbox2->Add(radioBox1, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 5);

    vbox->Add(radioBox3, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 5);
    vbox2->Add(radioBox2, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 5);

    vbox2->Add(radioBox4, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 5);

    vbox2->Add(btn1, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 5);
    vbox2->Add(btn2, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 5);

    hbox->Add(vbox, 0, wxTOP | wxEXPAND, 15);
    hbox->Add(vbox2, 0, wxTOP | wxEXPAND, 15);

    this->SetSizer(hbox);
    Centre();

    Connect(2, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Dodawanie::anulujClicked));
    Connect(1, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Dodawanie::zatwierdzClicked));

}
void Dodawanie::anulujClicked(wxCommandEvent& event)
{
    this->Close(true);
}

int Dodawanie::obliczID()
{
    int id = spa->getKontenerLudzi().size() + 1;
    while (!sprawdzCzyIDistnieje(id)) {
        id++;
    }
    return id;
}

bool Dodawanie::sprawdzCzyIDistnieje(int id)
{
    for (auto el : spa->getKontenerLudzi()) {
        if (el.getID() == std::to_string(id)) {
            return false;
        }
    }
    return true;
}

//Ÿród³o: https://recluze.net/2019/04/21/split-string-to-int-vector-in-c/
std::vector<int> split(const std::string& s, char delimiter) {
    std::vector<int> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(stoi(token));
    }
    return tokens;
}


void Dodawanie::zatwierdzClicked(wxCommandEvent& event) {
    std::string id, imie, nazwisko, platnosc, zakwaterowanie, zwierzeta, wyzywienie, uslugi;
    id = std::to_string(obliczID());
    imie = std::string(tc1->GetValue().mb_str(wxConvUTF8));
    nazwisko = std::string(tc2->GetValue().mb_str(wxConvUTF8));
    uslugi = std::string(tc3->GetValue().mb_str(wxConvUTF8));
    platnosc = radioBox1->GetString(radioBox1->GetSelection());
    zwierzeta = radioBox2->GetString(radioBox2->GetSelection());
    zakwaterowanie = radioBox3->GetString(radioBox3->GetSelection());
    wyzywienie = radioBox4->GetString(radioBox4->GetSelection());
    
    std::vector<int> idUslug = split(uslugi, ' ');
    auto uslugiVector = spa->odczytUslugi.WczytajDaneUslugi(idUslug);

    auto odczyt = new OdczytOsoby();
    Osoba osoba = odczyt->stworzOsobe(id, imie, nazwisko, platnosc, zakwaterowanie, zwierzeta, wyzywienie);
    for (auto& el : uslugiVector) {
        osoba.dodajUsluge(el);
    }
    osoba.obliczCene();
    spa->getKontenerLudzi().push_back(osoba);
    
    

    okno->wyswietl();
    spa->Zapisz();
    spa->ZapiszDane();
    this->Close(true);
}
