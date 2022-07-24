#include "Factory.h"
#include "cMain.h"

wxButton* Factory::createButton(wxFrame* par, wxWindowID ID, wxString title, int xPoint, int yPoint, int xSize, int ySize) {
	wxButton* output = new wxButton(par, ID, title, wxPoint(xPoint, yPoint), wxSize(xSize, ySize));
	return output;

}

wxButton* Factory::createButton(wxFrame* par, wxWindowID ID, wxString title, int xPoint, int yPoint) {
	wxButton* output = new wxButton(par, ID, title, wxPoint(xPoint, yPoint), wxSize(70, 50));
	return output;

}
