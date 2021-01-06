#pragma once
#include <wx/wx.h>
#include "SPA.h"
#include "Okno.h"

class Dodawanie : public wxFrame
{
public:
	Dodawanie(wxPoint pos, SPA* spa, Okno* okno);
private:
	void anulujClicked(wxCommandEvent& event);
	void zatwierdzClicked(wxCommandEvent& event);
	wxTextCtrl* tc1;
	wxTextCtrl* tc2;
	wxTextCtrl* tc3;
	wxRadioBox* radioBox1;
	wxRadioBox* radioBox2;
	wxRadioBox* radioBox3;
	wxRadioBox* radioBox4;
	SPA* spa;
	Okno* okno;
};

