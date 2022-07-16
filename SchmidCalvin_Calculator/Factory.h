#pragma once
#include "wx/wx.h"
#include "cMain.h"

static class Factory
{
public:
	wxButton* createButton(wxFrame* par, wxWindowID ID, wxString title, int xPoint, int yPoint, int xSize, int ySize);
	wxButton* createButton(wxFrame* par, wxWindowID ID, wxString title, int xPoint, int yPoint);
};

