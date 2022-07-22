#pragma once
#include "wx/wx.h"
#include "Command.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiply.h"
#include "Division.h"
#include "Mod.h"
#include "Calculator.h"
#include <vector>

class Processor
{
private:
	static Processor* _processor;
	bool firstLine;
	std::vector<Command*> _queue;
	Calculator* _calc;
	Processor() {
		_calc = new Calculator();
		firstLine = true;
	}
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
			_calc->setLine(wxStringToFloat(textbox->GetLineText(0)));
		}
		else {  //If the button wasn't a number, process the corresponding opperation (7/19/22)
			switch (ID) {

			case 10010: { //Negative
				_calc->setLine(0 - _calc->getLine());
				textbox->Clear();
				textbox->AppendText(wxString::Format(wxT("%g"), _calc->getLine()));
				break;
			}
			case 10011: {//Clear
				//Clears the text box, and resets the numbers for the calculation
				textbox->Clear();
				_calc->setLine(0);
				firstLine = true;
				break;
			}
			case 10012: {//Binary
				if (firstLine) {
					std::string binary = "";
					int number = (int)_calc->getLine();

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
					_calc->setLine(0);
				}
				break;
			}
			case 10013: {//Hexidecimal
				if (firstLine) {
					std::string hex = "";
					int number = (int)_calc->getLine();

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
					_calc->setLine(0);
				}
				break;
			}
			case 10014: {//Mod
				if (firstLine) {
					Mod* mod = new Mod(_calc->getLine(), _calc);
					_queue.push_back(mod);
					textbox->Clear();
					firstLine = false;
				}
				break;
			}
			case 10015: {//Divide
				if (firstLine) {
					Division* div = new Division(_calc->getLine(), _calc);
					_queue.push_back(div);
					textbox->Clear();
					firstLine = false;
				}
				break;
			}
			case 10016: {//Multiply
				if (firstLine) {
					Multiply* multi = new Multiply(_calc->getLine(), _calc);
					_queue.push_back(multi);
					textbox->Clear();
					firstLine = false;
				}
			}
			case 10017: {//Subtract
				if (firstLine) {
					Subtraction* sub = new Subtraction(_calc->getLine(), _calc);
					_queue.push_back(sub);
					textbox->Clear();
					firstLine = false;
				}
				break;
			}
			case 10018: {//Equals
				Calculate();

				textbox->Clear();
				textbox->AppendText(wxString::Format(wxT("%f"), _calc->getAnswer()));
				break;
			}
			case 10019: {//Decimal
				textbox->AppendText(btn->GetLabel());
				break;
			}
			case 10020: {//Add
				if (firstLine) {
					Addition* add = new Addition(_calc->getLine(), _calc);
					_queue.push_back(add);
					textbox->Clear();
					firstLine = false;
				}
				break;
			}
			}
		}
	}

	//Run through the command queue (7/22/22)
	void Calculate(){
		for (int i = 0; i < _queue.size(); i++) {
			_queue[i]->Execute();
		}
		_queue.clear();
	}
};

Processor* Processor::_processor = nullptr;

