#pragma once
#include "wx/wx.h"


class cMain : public wxFrame
{

public:
	cMain();
	void OnButtonClick(wxCommandEvent& evt);
	void BindButton(wxButton* btn);
private:
	wxButton* btn1 = nullptr;
	wxButton* btn2 = nullptr;
	wxButton* btn3 = nullptr;
	wxButton* btn4 = nullptr;
	wxButton* btn5 = nullptr;
	wxButton* btn6 = nullptr;
	wxButton* btn7 = nullptr;
	wxButton* btn8 = nullptr;
	wxButton* btn9 = nullptr;
	wxButton* btn0 = nullptr;
	wxButton* btnEquals = nullptr;
	wxButton* btnClear = nullptr;
	wxButton* btnAdd = nullptr;
	wxButton* btnSub = nullptr;
	wxButton* btnMulti = nullptr;
	wxButton* btnDiv = nullptr;
	wxButton* btnMod = nullptr;
	wxButton* btnHex = nullptr;
	wxButton* btnBin = nullptr;
	wxButton* btnNeg = nullptr;
	wxButton* btnDecimal = nullptr;
	wxTextCtrl* txtBox = nullptr;

	wxDECLARE_EVENT_TABLE();
};