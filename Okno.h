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
private:
	wxListCtrl* listCtrl;
	wxListItem* col0;
	wxListItem* col1;
	wxListItem* col2;
	wxListItem* col3;
	void wyswietl();
	SPA spa;
};

