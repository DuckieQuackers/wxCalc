#pragma once
#include "wx/wx.h"
#include <vector>

class Processor
{
private:
	static Processor* _processor;
	Processor() {}
	enum Operations {None, Plus, Minus, Multiply, Divide, Mod};
	float line = NULL;
	float line2 = NULL;
	float outcome;
	Operations operation = None;
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

	//Converts a variable of type wxString to a float (7/20/22)
	float wxStringToFloat(wxString line)
	{
		std::string number = std::string(line.mb_str());
		float output = std::stof(number);
		return output;
	}

	//Process the button commands
	void ProcessButton(wxButton* btn, wxTextCtrl* textbox) {
		//Get the button ID for future refrence (7/19/22)
		int ID = btn->GetId();

		//If the button clicked was a number, add it to the text box (7/19/22)
		//Record the number entered in a float variable and update it (7/20/22)
		if (ID >= 10000 && ID < 10010) {
			textbox->AppendText(btn->GetLabel());
			if(operation == None)
				line = wxStringToFloat(textbox->GetLineText(0));
			else
				line2 = wxStringToFloat(textbox->GetLineText(0));
		}
		else {  //If the button wasn't a number, process the corresponding opperation (7/19/22)
			switch (ID) {

			case 10010: { //Negative
				if (operation == None) {
					line = 0 - line;
					textbox->Clear();
					textbox->AppendText(wxString::Format(wxT("%g"), line));
				}
				else {
					line2 = 0 - line2;
					textbox->Clear();
					textbox->AppendText(wxString::Format(wxT("%g"), line2));
				}
				break;
			}
			case 10011: {//Clear
				//Clears the text box, and resets the numbers for the calculation
				textbox->Clear();
				line = NULL;
				operation = None;
				break;
			}
			case 10012: {//Binary
				if (operation == None) {
					std::string binary = "";
					int number = (int)line;

					for (int i = 0; i < 32; i++) {
						if (number % 2 == 0)
							binary = "0" + binary;
						else
							binary = "1" + binary;

						number /= 2;
					}

					wxString display(binary.c_str(), wxConvUTF8);
					textbox->Clear();
					textbox->AppendText(display);
					line = NULL;
				}
				break;
			}
			case 10013: {//Hexidecimal
				if (operation == None) {
					std::string hex = "";
					int number = (int)line;

					while (number > 0) {
						int mod = number % 16;
						if (mod < 10) {
							hex = std::to_string(mod) + hex;
						}
						else {
							switch (mod)
							{
							case 10:
								hex = "A" + hex;
								break;
							case 11:
								hex = "B" + hex;
								break;
							case 12:
								hex = "C" + hex;
								break;
							case 13:
								hex = "D" + hex;
								break;
							case 14:
								hex = "E" + hex;
								break;
							case 15:
								hex = "F" + hex;
								break;
							}
						}

						number /= 16;
					}

					hex = "0x" + hex;

					wxString display(hex.c_str(), wxConvUTF8);
					textbox->Clear();
					textbox->AppendText(hex);
					line = NULL;
				}
				break;
			}
			case 10014: {//Mod
				if (operation == None) {
					operation = Mod;
					textbox->Clear();
				}
				break;
			}
			case 10015: {//Divide
				if (operation == None) {
					operation = Divide;
					textbox->Clear();
				}
				break;
			}
			case 10016: {//Multiply
				if (operation == None) {
					operation = Multiply;
					textbox->Clear();
				}
				break;
			}
			case 10017: {//Subtract
				if (operation == None) {
					operation = Minus;
					textbox->Clear();
				}
				break;
			}
			case 10018: {//Equals
				outcome = Calculate(line, line2, operation);

				textbox->Clear();
				textbox->AppendText(wxString::Format(wxT("%f"), outcome));

				line = outcome;
				line2 = NULL;
				operation = None;
				break;
			}
			case 10019: {//Decimal
				textbox->AppendText(btn->GetLabel());
				break;
			}
			case 10020: {//Add
				if (operation == None) {
					operation = Plus;
					textbox->Clear();
				}
				break;
			}
			}
		}
	}

	//Calculate a math equation made from a string
	float Calculate(float line1, float line2, Operations operation){

		float output = 0;

		switch (operation)
		{
		case Plus:
			output = line1 + line2;
			break;
		case Minus:
			output = line1 - line2;
			break;
		case Multiply:
			output = line1 * line2;
			break;
		case Divide:
			output = line1 / line2;
			break;
		case Mod:
			output = (int) line1 % (int) line2;
			break;
		}

		return output;
	}
};

Processor* Processor::_processor = nullptr;

