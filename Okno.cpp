#include "Okno.h"
#include "Dodawanie.h"

Okno::Okno(const wxString& title, const wxPoint& pos, const wxSize& size, SPA spa)
    : wxFrame(NULL, wxID_ANY, title, pos, size), spa(spa)
{
    wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);
    wxMenuBar* menuBar = new wxMenuBar;
    wxMenu* file = new wxMenu;
    wxMenu* help = new wxMenu;
    file->Append(1, wxT("&Zmieñ Profil"));
    file->Append(2, wxT("&Skanuj"));
    file->Append(3, wxT("&Synchronizuj"));
    file->Append(4, wxT("&Zmieñ kierunek"));
    file->Append(5, wxT("&Wyjœcie"));
    help->Append(6, wxT("&O Programie"));
    menuBar->Append(file, wxT("&Menu"));
    menuBar->Append(help, wxT("&Pomoc"));
    SetMenuBar(menuBar);

    wxBoxSizer* mainHbox = new wxBoxSizer(wxHORIZONTAL);
    listCtrl = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);

    col0 = new wxListItem();
    col1 = new wxListItem();
    col2 = new wxListItem();
    col3 = new wxListItem();
    col0->SetId(7);
    col1->SetId(8);
    col2->SetId(9);
    col3->SetId(10);
    col0->SetText(_("ID"));
    col1->SetText(_("Imiê"));
    col2->SetText(_("Nazwisko"));
    col3->SetText(_("Koszt"));
    col0->SetWidth(50);
    col1->SetWidth(150);
    col2->SetWidth(150);
    col3->SetWidth(100);
    listCtrl->InsertColumn(0, *col0);
    listCtrl->InsertColumn(1, *col1);
    listCtrl->InsertColumn(2, *col2);
    listCtrl->InsertColumn(3, *col3);

    mainHbox->Add(listCtrl, 1, wxEXPAND);

    wxBoxSizer* prawyvbox = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* hbox2 = new wxBoxSizer(wxHORIZONTAL);
    wxButton* btn1 = new wxButton(this, 1, wxT("Dodaj"));
    wxButton* btn2 = new wxButton(this, 2, wxT("Wybierz"));
    wxButton* btn3 = new wxButton(this, 3, wxT("Usuñ"));

    hbox2->Add(btn1, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 15);
    hbox2->Add(btn2, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 15);
    hbox2->Add(btn3, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 15);
    prawyvbox->Add(hbox2, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 15);

    wxStaticText* st1 = new wxStaticText(this, wxID_ANY, wxT("Podsumowanie:"));
    st2 = new wxStaticText(this, wxID_ANY, wxT("ID:"));
    st3 = new wxStaticText(this, wxID_ANY, wxT("Imiê:"));
    st4 = new wxStaticText(this, wxID_ANY, wxT("P³atnoœæ:"));
    st5 = new wxStaticText(this, wxID_ANY, wxT("Zakwaterowanie:"));
    st6 = new wxStaticText(this, wxID_ANY, wxT("Zwierzêta:"));
    st7 = new wxStaticText(this, wxID_ANY, wxT("Wy¿ywienie:"));
    st8 = new wxStaticText(this, wxID_ANY, wxT("Us³ugi:"));
    st9 = new wxStaticText(this, wxID_ANY, wxT("Koszt:"));
    prawyvbox->Add(st1, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 5);
    prawyvbox->Add(st2, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 5);
    prawyvbox->Add(st3, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 5);
    prawyvbox->Add(st4, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 5);
    prawyvbox->Add(st5, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 5);
    prawyvbox->Add(st6, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 5);
    prawyvbox->Add(st7, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 5);
    prawyvbox->Add(st8, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 5);
    prawyvbox->Add(st9, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 5);


    hbox->Add(mainHbox, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 15);
    hbox->Add(prawyvbox, 0, wxTOP | wxEXPAND, 15);
    this->SetSizer(hbox);
    wyswietl();
    Centre();

    Connect(2, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Okno::wybierzClicked));
    Connect(1, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Okno::dodajClicked));
    Connect(3, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Okno::usunClicked));

}

void Okno::usunClicked(wxCommandEvent& event) {
    long lSelectedItem = listCtrl->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
    int selection = spa.getKontenerLudzi().size() - lSelectedItem - 1;
    if (lSelectedItem >= 0) {
        podsumowanie(selection);
    }
    spa.getKontenerLudzi().erase(spa.getKontenerLudzi().begin() + selection);
    spa.Zapisz();
    spa.ZapiszDane();
    wyswietl();
}

void Okno::wyswietl() {
    listCtrl->DeleteAllItems();
    for (auto osoba : spa.getKontenerLudzi()) {
        long itemIndex = listCtrl->InsertItem(0, osoba.getID());
        listCtrl->SetItem(itemIndex, 1, osoba.getImie());
        listCtrl->SetItem(itemIndex, 2, osoba.getNazwisko());
        listCtrl->SetItem(itemIndex, 3, std::to_string(osoba.getCena()));
    }
}

void Okno::wybierzClicked(wxCommandEvent& event) {
    long lSelectedItem = listCtrl->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
    int selection = spa.getKontenerLudzi().size() - lSelectedItem - 1;
    if (lSelectedItem >= 0) {
        podsumowanie(selection);
    }
}

void Okno::dodajClicked(wxCommandEvent& event) {
    Dodawanie* dodawanie = new Dodawanie(this->GetPosition(), &spa, this);
    dodawanie->Show(true);
}

void Okno::podsumowanie(int selection) {
    st2->SetLabelText("ID: " + spa.getKontenerLudzi().at(selection).getID());
    st3->SetLabelText("Imiê: " + spa.getKontenerLudzi().at(selection).getImie() + " " + spa.getKontenerLudzi().at(selection).getNazwisko());
    st4->SetLabelText("P³atnoœæ: " + spa.getKontenerLudzi().at(selection).getPlatnosc().getOpis());
    st5->SetLabelText("Zakwaterowanie: " + spa.getKontenerLudzi().at(selection).getZakwaterowanie().getOpis() );
    st6->SetLabelText("Zwierzêta: " + spa.getKontenerLudzi().at(selection).getZwierzeta().getOpis());
    st7->SetLabelText("Wy¿ywienie: " + spa.getKontenerLudzi().at(selection).getWyzywienie().getOpis());
    std::string out;
    for (auto& el : spa.getKontenerLudzi().at(selection).getKupioneUslugi()) {
        out += std::to_string(el.getId()) + " ";
    }
    st8->SetLabelText("Us³ugi: " + out);
    st9->SetLabelText("Koszt: " + std::to_string(spa.getKontenerLudzi().at(selection).getCena()));
}
