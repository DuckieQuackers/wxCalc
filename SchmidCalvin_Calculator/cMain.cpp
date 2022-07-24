#include "cMain.h"
#include "Factory.h"
#include "Processor.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_BUTTON(10000, OnButtonClick)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(20, 20), wxSize(370, 400)) {

	Factory fact;

	//First row (7/8/22)
	btnNeg = fact.createButton(this, 10010, "Neg(-)", 270, 15, 70, 30);
	BindButton(btnNeg);
	txtBox = new wxTextCtrl(this, wxID_ANY, "", wxPoint(15, 17), wxSize(240, 25));

	//Second row (7/8/22)
	btnClear = fact.createButton(this, 10011, "C", 15, 60);
	BindButton(btnClear);
	btnBin = fact.createButton(this, 10012, "Bin", 100, 60);
	BindButton(btnBin);
	btnHex = fact.createButton(this, 10013, "Hex", 185, 60);
	BindButton(btnHex);
	btnMod = fact.createButton(this, 10014, "Mod", 270, 60);
	BindButton(btnMod);

	//Third row (7/8/22)
	btn7 = fact.createButton(this, 10007, "7", 15, 120);
	BindButton(btn7);
	btn8 = fact.createButton(this, 10008, "8", 100, 120);
	BindButton(btn8);
	btn9 = fact.createButton(this, 10009, "9", 185, 120);
	BindButton(btn9);
	btnDiv = fact.createButton(this, 10015, "/", 270, 120);
	BindButton(btnDiv);

	//Fourth row (7/8/22)
	btn4 = fact.createButton(this, 10004, "4", 15, 180);
	BindButton(btn4);
	btn5 = fact.createButton(this, 10005, "5", 100, 180);
	BindButton(btn5);
	btn6 = fact.createButton(this, 10006, "6", 185, 180);
	BindButton(btn6);
	btnMulti = fact.createButton(this, 10016, "*", 270, 180);
	BindButton(btnMulti);

	//Fifth row (7/8/22)
	btn1 = fact.createButton(this, 10001, "1", 15, 240);
	BindButton(btn1);
	btn2 = fact.createButton(this, 10002, "2", 100, 240);
	BindButton(btn2);
	btn3 = fact.createButton(this, 10003, "3", 185, 240);
	BindButton(btn3);
	btnSub = fact.createButton(this, 10017, "-", 270, 240);
	BindButton(btnSub);


	//Bottom row (7/8/22)
	btnEquals = fact.createButton(this, 10018, "=", 15, 300);
	BindButton(btnEquals);
	btn0 = fact.createButton(this, 10000, "0", 100, 300);
	BindButton(btn0);
	btnDecimal = fact.createButton(this, 10019, ".", 185, 300);
	BindButton(btnDecimal);
	btnAdd = fact.createButton(this, 10020, "+", 270, 300);
	BindButton(btnAdd);
}

//Function to handle button presses (7/11/22)
void cMain::OnButtonClick(wxCommandEvent& evt) {
	//Casts the event object as a button so the label can be retrived (7/11/22)
	Processor* process = Processor::GetInstance();
	wxButton* btn = static_cast<wxButton*>(evt.GetEventObject());
	process->ProcessButton(btn, txtBox);;
}

void cMain::BindButton(wxButton* btn) {
	btn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnButtonClick, this);
}