#pragma once
#include <wx/wx.h>
#include <wx/listctrl.h>
#include "SPA.h"
#include <wx/statline.h>
#include <wx/stattext.h>


class Okno : public wxFrame
{
public:
	Okno(const wxString& title, const wxPoint& pos, const wxSize& size, SPA spa);
	void wyswietl();
private:
	wxListCtrl* listCtrl;
	wxListItem* col0;
	wxListItem* col1;
	wxListItem* col2;
	wxListItem* col3;
	wxStaticText* st2;
	wxStaticText* st3;
	wxStaticText* st4;
	wxStaticText* st5;
	wxStaticText* st6;
	wxStaticText* st7;
	wxStaticText* st8;
	wxStaticText* st9;
	void wybierzClicked(wxCommandEvent& event);
	void dodajClicked(wxCommandEvent& event);
	void podsumowanie(int selection);
	SPA spa;
};

