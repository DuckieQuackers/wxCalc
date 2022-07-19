#pragma once
#include "wx/wx.h"
#include <vector>

class Processor
{
private:
	static Processor* _processor;
	Processor() {}
public:
	//Create the method to get the singleton instance (7/19/22)
	static Processor* GetInstance() {
		if (_processor == nullptr) {
			_processor = new Processor();
		}

		return _processor;
	}

	//Delete the copy and assignment operators (7/19/22)
	Processor(Processor& other) = delete;
	void operator=(Processor& other) = delete;

	//Process the button commands
	void ProcessButton(wxButton* btn, wxTextCtrl* textbox) {
		//Get the button ID for future refrence (7/19/22)
		int ID = btn->GetId();

		//If the button clicked was a number, add it to the text box (7/19/22)
		if (ID >= 10000 && ID < 10010) {
			textbox->AppendText(btn->GetLabel());
		}
		else {  //If the button wasn't a number, process the corresponding opperation (7/19/22)
			switch (ID) {
			case 10010: //Negative
				break;
			case 10011: //Clear
				textbox->Clear();
				break;
			case 10012: //Bin
				break;
			case 10013: //Hex
				break;
			case 10014: //Mod
				break;
			case 10015: //Divide
				textbox->AppendText(" " + btn->GetLabel() + " ");
				break;
			case 10016: //Multiply
				textbox->AppendText(" " + btn->GetLabel() + " ");
				break;
			case 10017: //Subtract
				textbox->AppendText(" " + btn->GetLabel() + " ");
				break;
			case 10018: //Equals
				/*float outcome = Calculate(textbox->GetLineText(0));
				textbox->Clear();
				textbox->AppendText(wxString::Format(wxT("%f"), outcome));*/
				break;
			case 10019: //Decimal
				textbox->AppendText(btn->GetLabel());
				break;
			case 10020: //Add
				textbox->AppendText(" " + btn->GetLabel() + " ");
				break;
			}
		}
	}

	//Calculate a math equation made from a string
	float Calculate(wxString input){
		std::string equation = std::string(input.mb_str());
	}
};

Processor* Processor::_processor = nullptr;

