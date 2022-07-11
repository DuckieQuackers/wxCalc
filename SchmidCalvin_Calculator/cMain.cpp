#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_BUTTON(10000, OnButtonClick)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(20, 20), wxSize(370, 400)) {
	//First row (7/8/22)
	btnNeg = new wxButton(this, 10010, "Neg(-)", wxPoint(270, 15), wxSize(70, 30));
	txtBox = new wxTextCtrl(this, wxID_ANY, "", wxPoint(15, 17), wxSize(240, 25));

	//Second row (7/8/22)
	btnClear = new wxButton(this, 10011, "C", wxPoint(15, 60), wxSize(70, 50));
	btnBin = new wxButton(this, 10012, "Bin", wxPoint(100, 60), wxSize(70, 50));
	btnHex = new wxButton(this, 10013, "Hex", wxPoint(185, 60), wxSize(70, 50));
	btnMod = new wxButton(this, 10014, "Mod", wxPoint(270, 60), wxSize(70, 50));

	//Third row (7/8/22)
	btn7 = new wxButton(this, 10007, "7", wxPoint(15, 120), wxSize(70, 50));
	btn8 = new wxButton(this, 10008, "8", wxPoint(100, 120), wxSize(70, 50));
	btn9 = new wxButton(this, 10009, "9", wxPoint(185, 120), wxSize(70, 50));
	btnDiv = new wxButton(this, 10015, "/", wxPoint(270, 120), wxSize(70, 50));

	//Fourth row (7/8/22)
	btn4 = new wxButton(this, 10004, "4", wxPoint(15, 180), wxSize(70, 50));
	btn5 = new wxButton(this, 10004, "5", wxPoint(100, 180), wxSize(70, 50));
	btn6 = new wxButton(this, 10006, "6", wxPoint(185, 180), wxSize(70, 50));
	btnMulti = new wxButton(this, 10016, "*", wxPoint(270, 180), wxSize(70, 50));

	//Fifth row (7/8/22)
	btn1 = new wxButton(this, 10001, "1", wxPoint(15, 240), wxSize(70, 50));
	btn2 = new wxButton(this, 10002, "2", wxPoint(100, 240), wxSize(70, 50));
	btn3 = new wxButton(this, 10003, "3", wxPoint(185, 240), wxSize(70, 50));
	btnSub = new wxButton(this, 10017, "-", wxPoint(270, 240), wxSize(70, 50));
	

	//Bottom row (7/8/22)
	btnEquals = new wxButton(this, 10018, "=", wxPoint(15, 300), wxSize(70, 50));
	btn0 = new wxButton(this, 10000, "0", wxPoint(100, 300), wxSize(70, 50));
	btnDecimal = new wxButton(this, 10019, ".", wxPoint(185, 300), wxSize(70, 50));
	btnAdd = new wxButton(this, 10020, "+", wxPoint(270, 300), wxSize(70, 50));

	//Bind all the buttons to the event table
	BindButton(btn1);
	BindButton(btn2);
	BindButton(btn3);
	BindButton(btn4);
	BindButton(btn5);
	BindButton(btn6);
	BindButton(btn7);
	BindButton(btn8);
	BindButton(btn9);
	BindButton(btn0);
	BindButton(btnAdd);
	BindButton(btnSub);
	BindButton(btnMulti);
	BindButton(btnDiv);
	BindButton(btnEquals);
	BindButton(btnDecimal);
	BindButton(btnClear);
	BindButton(btnBin);
	BindButton(btnHex);
	BindButton(btnMod);
	BindButton(btnNeg);
}

//Function to handle button presses (7/11/22)
void cMain::OnButtonClick(wxCommandEvent& evt) {
	//Casts the event object as a button so the label can be retrived (7/11/22)
	wxButton* btn = static_cast<wxButton*>(evt.GetEventObject());
	txtBox->AppendText(btn->GetLabel());
}

//Function to bind the buttons to the event table (7/11/22)
void cMain::BindButton(wxButton* btn) {
	btn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnButtonClick, this);
}