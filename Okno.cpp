#include "Okno.h"

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
    wxButton* btn3 = new wxButton(this, 2, wxT("Usuñ"));

    hbox2->Add(btn1, 0, wxBOTTOM, 15);
    hbox2->Add(btn2, 0, wxBOTTOM, 15);
    hbox2->Add(btn3, 0, wxBOTTOM, 15);
    prawyvbox->Add(hbox2, 0, wxLEFT | wxBOTTOM | wxTOP | wxEXPAND, 15);

    wxStaticText* st1 = new wxStaticText(this, wxID_ANY, wxT("Podsumowanie:"));
    wxStaticText* st2 = new wxStaticText(this, wxID_ANY, wxT("ID:"));
    wxStaticText* st3 = new wxStaticText(this, wxID_ANY, wxT("Imiê:"));
    wxStaticText* st4 = new wxStaticText(this, wxID_ANY, wxT("P³atnoœæ:"));
    wxStaticText* st5 = new wxStaticText(this, wxID_ANY, wxT("Zakwaterowanie:"));
    wxStaticText* st6 = new wxStaticText(this, wxID_ANY, wxT("Zwierzêta:"));
    wxStaticText* st7 = new wxStaticText(this, wxID_ANY, wxT("Wy¿ywienie:"));
    wxStaticText* st8 = new wxStaticText(this, wxID_ANY, wxT("Us³ugi:"));
    wxStaticText* st9 = new wxStaticText(this, wxID_ANY, wxT("Koszt:"));
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
