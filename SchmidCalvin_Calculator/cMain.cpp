#include "cMain.h"

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(20, 20), wxSize(370, 400)) {
	//First row (7/8/22)
	btnNeg = new wxButton(this, wxID_ANY, "Neg(-)", wxPoint(270, 15), wxSize(70, 30));
	txtBox = new wxTextCtrl(this, wxID_ANY, "", wxPoint(15, 17), wxSize(240, 25));

	//Second row (7/8/22)
	btnClear = new wxButton(this, wxID_ANY, "C", wxPoint(15, 60), wxSize(70, 50));
	btnBin = new wxButton(this, wxID_ANY, "Bin", wxPoint(100, 60), wxSize(70, 50));
	btnHex = new wxButton(this, wxID_ANY, "Hex", wxPoint(185, 60), wxSize(70, 50));
	btnMod = new wxButton(this, wxID_ANY, "Mod", wxPoint(270, 60), wxSize(70, 50));

	//Third row (7/8/22)
	btn7 = new wxButton(this, wxID_ANY, "7", wxPoint(15, 120), wxSize(70, 50));
	btn8 = new wxButton(this, wxID_ANY, "8", wxPoint(100, 120), wxSize(70, 50));
	btn9 = new wxButton(this, wxID_ANY, "9", wxPoint(185, 120), wxSize(70, 50));
	btnDiv = new wxButton(this, wxID_ANY, "/", wxPoint(270, 120), wxSize(70, 50));

	//Fourth row (7/8/22)
	btn4 = new wxButton(this, wxID_ANY, "4", wxPoint(15, 180), wxSize(70, 50));
	btn5 = new wxButton(this, wxID_ANY, "5", wxPoint(100, 180), wxSize(70, 50));
	btn6 = new wxButton(this, wxID_ANY, "6", wxPoint(185, 180), wxSize(70, 50));
	btnMulti = new wxButton(this, wxID_ANY, "*", wxPoint(270, 180), wxSize(70, 50));

	//Fifth row (7/8/22)
	btn1 = new wxButton(this, wxID_ANY, "1", wxPoint(15, 240), wxSize(70, 50));
	btn2 = new wxButton(this, wxID_ANY, "2", wxPoint(100, 240), wxSize(70, 50));
	btn3 = new wxButton(this, wxID_ANY, "3", wxPoint(185, 240), wxSize(70, 50));
	btnSub = new wxButton(this, wxID_ANY, "-", wxPoint(270, 240), wxSize(70, 50));

	//Bottom row (7/8/22)
	btnEquals = new wxButton(this, wxID_ANY, "=", wxPoint(15, 300), wxSize(70, 50));
	btn0 = new wxButton(this, wxID_ANY, "0", wxPoint(100, 300), wxSize(70, 50));
	btnDecimal = new wxButton(this, wxID_ANY, ".", wxPoint(185, 300), wxSize(70, 50));
	btnAdd = new wxButton(this, wxID_ANY, "+", wxPoint(270, 300), wxSize(70, 50));
}